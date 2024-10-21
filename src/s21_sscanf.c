#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int count_success = 0;
  va_list argument;
  va_start(argument, format);
  scan_spec spec = {0};

  int flag_error = 0;
  while (*format && flag_error == 0) {
    if (*format != '%') {
      if (*str != *format && !isspace(*format)) {
        flag_error = 1;
      }
      if (!isspace(*format) || *format == *str) {
        str++;
        spec.n_flag++;
      }
      format++;
    } else {
      format++;
      if (*format == '%') {
        if (*str == '%') {
          format++;
          str++;
          spec.n_flag++;
        } else {
          flag_error = 1;
        }
      } else {
        format = pars_star(format, &spec);
        format = pars_width(format, &spec);
        format = pars_length(format, &spec);
        format = pars_spec(format, &spec);

        const char *start_str = str;
        char *integer = "diouxX";
        char *float_double = "eEfgG";
        if (spec.specifier == 'c') {
          char *c = S21_NULL;
          if (!spec.star) {
            c = va_arg(argument, char *);
            *c = *str;
            count_success++;
          }
          str++;
          spec.n_flag++;
          format++;
        } else if (s21_strchr(integer, spec.specifier)) {
          integer_flags(&argument, &str, start_str, &spec);
          format++;
        } else if (s21_strchr(float_double, spec.specifier)) {
          float_flags(&argument, &str, &spec);
          format++;
        } else if (spec.specifier == 'p') {
          void **p = va_arg(argument, void **);
          *p = S21_NULL;
          hexadecimal_pointer(&str, start_str, p, &spec);
        } else if (spec.specifier == 's') {
          s_flag(&argument, &str, &spec);
          format++;
        } else if (spec.specifier == 'n') {
          int *n = S21_NULL;
          if (!spec.star) {
            n = va_arg(argument, int *);
            *n = spec.n_flag;
          }
          format++;
        }
      }
    }
    while (isspace(*str)) {
      str++;
      spec.n_flag++;
    }
    spec.width = 0;
    spec.minus = 0;
    spec.star = 0;
  }
  count_success += spec.success;
  return count_success;
}

const char *pars_width(const char *format, scan_spec *spec) {
  int width = 0;
  while (isdigit(*format)) {
    while (isdigit(*format)) {
      width = width * 10 + (*format - '0');
      format++;
    }
    spec->width = width;
  }
  return format;
}

const char *pars_length(const char *format, scan_spec *spec) {
  char *length = "Llh";
  if (s21_strchr(length, *format)) {
    spec->length = *format;
    format++;
  }
  return format;
}

const char *pars_star(const char *format, scan_spec *spec) {
  char *star = "*";
  if (s21_strchr(star, *format)) {
    spec->star = *format;
    format++;
  }
  return format;
}

const char *pars_spec(const char *format, scan_spec *spec) {
  char *specifiers = "cdieEfgGosuxXpn%";
  if (s21_strchr(specifiers, *format)) {
    spec->specifier = *format;
  }
  return format;
}

int pars_minus(const char *str, scan_spec *spec) {
  spec->minus = 0;
  if (str[0] == '-') spec->minus = 1;
  return spec->minus;
}

void integer_flags(va_list *argument, const char **str, const char *start_str,
                   scan_spec *spec) {
  if (pars_minus(*str, spec) || **str == '+') {
    if (spec->width != 1) {
      if (spec->width != 0) spec->width -= 1;
      (*str)++;
      spec->n_flag++;
      start_str++;
    }
  }
  long int result;
  char *oct_hex = "ioxX";
  if (spec->specifier == 'd' || spec->specifier == 'u') {
    result = decimal(str, start_str, spec);
  } else if (s21_strchr(oct_hex, spec->specifier)) {
    result = oct_hex_flags(str, start_str, spec);
  }
  if (spec->minus != 0) result *= -1;

  if (spec->length == 'h') {
    short int *hx = S21_NULL;
    if (!spec->star) {
      hx = va_arg(*argument, short int *);
      *hx = result;
    }
  } else if (spec->length == 'l') {
    long int *lx = S21_NULL;
    if (!spec->star) {
      lx = va_arg(*argument, long int *);
      *lx = result;
    }
  } else {
    int *x = S21_NULL;
    if (!spec->star) {
      x = va_arg(*argument, int *);
      *x = result;
    }
  }
  if (*str - start_str != 0) spec->success++;
  if (spec->star && (*str - start_str != 0)) spec->success--;
}

long int oct_hex_flags(const char **str, const char *start_str,
                       scan_spec *spec) {
  long int value;
  if (spec->specifier == 'i') {
    if (**str == '0' && spec->width != 1) {
      (*str)++;
      spec->n_flag++;
      if (**str == 'x' || **str == 'X') {
        (*str)++;
        spec->n_flag++;
        value = hexadecimal(str, start_str, spec);
      } else {
        value = octal(str, start_str, spec);
      }
    } else {
      value = decimal(str, start_str, spec);
    }
  } else if (spec->specifier == 'o') {
    if (**str == '0') {
      (*str)++;
      spec->n_flag++;
    }
    value = octal(str, start_str, spec);
  } else {
    if (**str == '0') {
      (*str)++;
      spec->n_flag++;
      if (**str == 'x' || **str == 'X') {
        (*str)++;
        spec->n_flag++;
      }
    }
    value = hexadecimal(str, start_str, spec);
  }
  return value;
}

long int decimal(const char **str, const char *start_str, scan_spec *spec) {
  long int num = 0;
  while (isdigit(**str) &&
         ((*str - start_str) < spec->width || spec->width == 0)) {
    num = num * 10 + (**str - '0');
    spec->n_flag++;
    (*str)++;
  }
  return num;
}

long int octal(const char **str, const char *start_str, scan_spec *spec) {
  long int num = 0;
  while (isdigit(**str) &&
         ((*str - start_str) < spec->width || spec->width == 0) &&
         (**str - '0' < 8)) {
    num = num * 8 + (**str - '0');
    (*str)++;
    spec->n_flag++;
  }
  return num;
}

long int hexadecimal(const char **str, const char *start_str, scan_spec *spec) {
  long int num = 0;
  while (isxdigit(**str) &&
         ((*str - start_str) < spec->width || spec->width == 0)) {
    if (isdigit(**str)) {
      num = num * 16 + (**str - '0');
    } else {
      char c = tolower(**str);
      num = num * 16 + (c - 'a' + 10);
    }
    (*str)++;
    spec->n_flag++;
  }
  return num;
}

void float_flags(va_list *argument, const char **str, scan_spec *spec) {
  if (pars_minus(*str, spec)) {
    (*str)++;
    spec->n_flag++;
  }
  if (spec->length == 'L') {
    length_longdouble(argument, str, spec);
  } else {
    length_float(argument, str, spec);
  }
}

void length_longdouble(va_list *argument, const char **str, scan_spec *spec) {
  long double *d = S21_NULL;
  if (!spec->star) d = va_arg(*argument, long double *);
  char *f_str = get_float_str(str, spec);
  if (!spec->star) {
    *d = strtold(f_str, S21_NULL);
    if (spec->minus != 0) *d = -*d;
  }
  free(f_str);
}

void length_float(va_list *argument, const char **str, scan_spec *spec) {
  float *f = S21_NULL;
  if (!spec->star) f = va_arg(*argument, float *);
  char *f_str = get_float_str(str, spec);
  if (!spec->star) {
    *f = strtof(f_str, S21_NULL);
    if (spec->minus != 0) *f = -*f;
  }
  free(f_str);
}

char *get_float_str(const char **str, scan_spec *spec) {
  const char *start_str = *str;
  int len = s21_strlen(*str);
  char *s = calloc(sizeof(char), s21_BF_SIZE);
  if (**str == '+') {
    if (spec->width != 1) {
      if (spec->width != 0) spec->width -= 1;
      (*str)++;
      spec->n_flag++;
      start_str++;
    } else {
      spec->success--;
    }
  }
  if (spec->width != 0) len = spec->width;
  int i = 0;
  int flag = 0;
  while (!flag && i < len && !isspace(*start_str) &&
         (isdigit(*start_str) || *start_str == '.' || *start_str == 'e' ||
          *start_str == '-' || *start_str == '+')) {
    if (*start_str == '.' && *(start_str + 1) == 'e') {
      flag = 1;
      spec->success--;
    }
    if (!spec->star) s[i] = *start_str;
    start_str++;
    i++;
  }
  if (!spec->star) {
    s[i] = '\0';
    if (start_str != *str) spec->success++;
  }
  (*str) += i;
  spec->n_flag += i;
  return s;
}

void hexadecimal_pointer(const char **str, const char *start_str,
                         void **pointer, scan_spec *spec) {
  *pointer = S21_NULL;
  if (**str == '0') {
    (*str) += 2;
    spec->n_flag += 2;
  }
  if (!spec->star) *pointer = (void *)hexadecimal(str, start_str, spec);
  spec->success++;
}

void s_flag(va_list *argument, const char **str, scan_spec *spec) {
  char *s = S21_NULL;
  if (!spec->star) s = va_arg(*argument, char *);
  const char *start_str = *str;
  int len = s21_strlen(*str);
  if (spec->width != 0) len = spec->width;

  int i = 0;
  while (i < len && *start_str != ' ') {
    if (!spec->star) s[i] = *start_str;
    start_str++;
    i++;
  }
  if (!spec->star) {
    s[i] = '\0';
    spec->success++;
  }
  (*str) += i;
  spec->n_flag += i;
}