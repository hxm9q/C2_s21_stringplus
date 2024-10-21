#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  char *str_start = str;
  int i = 0;
  va_list argument;
  va_start(argument, format);
  while (*format != '\0') {
    char buffer[BUFFER] = {'\0'};
    specificators spec = {0};
    if (*format == '%') {
      format++;
      while (parser_spec(*format)) {
        format = parser_flags(&spec, format);
        format = parser_width(&spec, format, argument);
        format = parser_accurancy(&spec, format, argument);
        format = parser_length(&spec, format);
      }
      main_parser(*format, buffer, spec, argument, str_start, str);
    } else {
      buffer[i] = *format;
    }
    format++;
    for (int j = 0; buffer[j]; j++, str++) {
      *str = buffer[j];
    }
  }
  va_end(argument);
  *str = '\0';
  return str - str_start;
}
void main_parser(char format, char *buffer, specificators spec,
                 va_list argument, char *str_start, char *str) {
  switch (format) {
    case 'c':
      parser_c(spec, buffer, argument);
      break;
    case 'd':
    case 'i':
      parser_int(spec, buffer, argument);
      break;
    case 'e':
    case 'E':
      spec.e_spec = format;
      parser_e(spec, buffer, argument);
      break;
    case 'f':
      parser_f(spec, buffer, argument);
      break;
    case 'g':
    case 'G':
      spec.e_spec = format;
      parser_g(spec, buffer, argument);
      break;
    case 'o':
      parser_o(spec, buffer, argument);
      break;
    case 's':
      parser_s(spec, buffer, argument);
      break;
    case 'u':
      parser_u(spec, buffer, argument);
      break;
    case 'x':
    case 'X':
      spec.e_spec = format;
      parser_x(spec, buffer, argument);
      break;
    case 'p':
      p_to_str(va_arg(argument, void *), buffer, spec);
      break;
    case 'n':
      n_to_str(str, str_start, argument);
      break;
    case '%':
      *buffer++ = '%';
      break;
  }
}
int parser_spec(const char format) {
  int result = 1;
  int number_of_specifiers = 16;
  const char spec[BUFFER] = {'c', 'd', 'i', 'e', 'E', 'f', 'g', 'G',
                             'o', 's', 'u', 'x', 'X', 'p', 'n', '%'};
  for (int i = 0; i < number_of_specifiers; i++) {
    if (spec[i] == format) {
      result = 0;
      i = number_of_specifiers;
    }
  }
  return result;
}
const char *parser_flags(specificators *spec, const char *format) {
  spec->specifier = ' ';
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    switch (*format) {
      case '-':
        spec->minus = 1;
        break;
      case '+':
        spec->plus = 1;
        break;
      case ' ':
        spec->space = 1;
        break;
      case '#':
        spec->sharp = 1;
        break;
      case '0':
        spec->specifier = '0';
        spec->zero = 1;
        break;
    }
    format++;
  }
  if (spec->minus) {
    spec->specifier = ' ';
  }
  return format;
}
const char *parser_width(specificators *spec, const char *format,
                         va_list argument) {
  int result = 0;
  if (*format == '*') {
    result = va_arg(argument, int);
    format++;
  }
  if (isdigit(*format)) {
    while (*format && isdigit(*format)) {
      result = result * 10 + (*format - '0');
      format++;
    }
  }
  spec->width = result;
  return format;
}
const char *parser_accurancy(specificators *spec, const char *format,
                             va_list argument) {
  int result = 0;
  if (*format == '.') {
    format++;
    if (isdigit(*format)) {
      while (*format && isdigit(*format)) {
        result = result * 10 + (*format - '0');
        format++;
      }
      if (result == 0) {
        result = -1;
      }
    } else {
      result = -2;
    }
  }
  if (*format == '*') {
    result = va_arg(argument, int);
    format++;
  }
  spec->accurancy = result;
  return format;
}
const char *parser_length(specificators *spec, const char *format) {
  switch (*format) {
    case 'h':
      spec->length = 'h';
      format++;
      break;
    case 'l':
      spec->length = 'l';
      format++;
      break;
    case 'L':
      spec->length = 'L';
      format++;
  }
  return format;
}
void parser_c(specificators spec, char *str, va_list argument) {
  char c = (char)va_arg(argument, int);
  char_to_string(spec, str, c);
}
void char_to_string(specificators spec, char *str, char c) {
  if (spec.minus) {
    *str = c;
    str++;
    for (int i = 1; i < spec.width; i++, str++) {
      *str = spec.specifier;
    }
  } else {
    for (int i = 1; i < spec.width; i++, str++) {
      *str = spec.specifier;
    }
    *str = c;
  }
}
void parser_int(specificators spec, char *str, va_list argument) {
  int64_t num = va_arg(argument, int64_t);
  handle_length_modifier(spec, &num);
  int_to_str(spec, str, num, 10);
}

void handle_length_modifier(specificators spec, int64_t *num) {
  switch (spec.length) {
    case 0:
      *num = (int32_t)(*num);
      break;
    case 'h':
      *num = (int16_t)(*num);
      break;
  }
}

void int_to_str(specificators spec, char *str, int64_t num, int base) {
  char buffer[1024];
  int num_count = 0, minus = 0;
  int64_t num_copy = num;
  if (spec.specifier == '0') {
    spec.zero = 1;
  }
  if (num < 0) {
    num *= -1;
    minus = 1;
  }
  if (num_copy == 0 && spec.accurancy != -1 && spec.accurancy != -2) {
    buffer[num_count++] = '0';
  }
  while (num > 0) {
    int digit = num % base;
    buffer[num_count++] = (char)('0' + digit);
    num -= digit;
    num /= base;
  }
  if (minus) {
    if (spec.zero) {
      *str++ = '-';
      spec.width--;
    }
  }
  if (num_copy > 0 && spec.plus) {
    if (spec.zero) {
      *str++ = '+';
      spec.width--;
    }
  }
  if (spec.space && spec.plus == 0 && num_copy >= 0 && spec.accurancy <= 0) {
    buffer[num_count++] = ' ';
  }
  int_write_to_array(spec, num_count, str, buffer, minus);
}
void int_write_to_array(specificators spec, int num_count, char *str,
                        char *buffer, int minus) {
  if (spec.accurancy) {
    spec.accurancy -= num_count;
    for (int j = 0; j < spec.accurancy; j++) {
      buffer[num_count++] = '0';
    }
  }

  if (spec.sharp && (spec.e_spec == 'x' || spec.e_spec == 'X')) {
    buffer[num_count++] = 'x';
    buffer[num_count++] = '0';
  }
  if (minus && spec.zero == 0) {
    buffer[num_count++] = '-';
  }
  if (spec.zero == 0 && spec.plus && minus == 0) {
    buffer[num_count++] = '+';
  }
  if (spec.minus) {
    char *str_copy = str + num_count;
    for (int j = num_count; j < spec.width; j++) {
      *str_copy = spec.specifier;
      str_copy++;
    }
  }
  if (spec.minus == 0) {
    for (int j = num_count; j < spec.width; j++) {
      buffer[num_count++] = spec.specifier;
    }
  }
  for (num_count--; num_count >= 0; num_count--) {
    *str++ = buffer[num_count];
  }
  if (spec.sharp) {
    *str = '\0';
  }
}
void parser_e(specificators spec, char *str, va_list argument) {
  long double num;
  if (spec.length == 'L') {
    num = va_arg(argument, long double);
  } else {
    num = va_arg(argument, double);
  }
  e_to_str(spec, str, num);
}
void e_to_str(specificators spec, char *str, long double num) {
  int e_count = 0, pos = 0, buffer[BUFFER] = {'\0'}, minus = 0;
  long double num_copy = num;
  if (num < 0 && num != 0) {
    num *= -1;
    minus = 1;
  }
  if (spec.accurancy == 0) {
    spec.accurancy = 6;
  }
  if (spec.space && num_copy == 0) {
    *str++ = ' ';
  }
  if (num != 0) {
    e_logic(&spec, num, str, &pos, &e_count, buffer, minus);
    str += s21_strlen(str);
    if (spec.sharp && spec.accurancy < 0) {
      *str++ = '.';
    }
    if (pos > 0) {
      *str++ = '.';
    }
    for (int t = spec.accurancy; 0 < t; t--) {
      *str++ = buffer[t] + '0';
    }
    str += s21_strlen(str);
    *str++ = spec.e_spec;
    if (e_count >= 0) {
      *str++ = '+';
    } else {
      *str++ = '-';
      e_count *= -1;
    }
    *(str + 1) = e_count % 10 + '0';
    e_count /= 10;
    *str++ = e_count % 10 + '0';
    if (spec.minus) {
      str++;
      for (int h = 6 + pos; h <= spec.width; h++) {
        *str++ = spec.specifier;
      }
    }
  } else {
    e_zero(spec, str);
  }
}
void e_logic(specificators *spec, long double num, char *str, int *pos,
             int *e_count, int *buffer, int minus) {
  long double i = 0;
  int count = 0;
  while (num < 1) {
    num *= 10;
    (*e_count)--;
  }
  while (num >= 10) {
    num /= 10;
    (*e_count)++;
  }
  num = modfl(num, &i);
  if (spec->accurancy <= 0) {
    i++;
  }
  int gg = 0;
  while (gg <= spec->accurancy) {
    num *= 10;
    gg++;
  }
  long long int num1 = roundl(num);
  while (count <= spec->accurancy) {
    buffer[count] = num1 % 10;
    num1 -= buffer[count];
    num1 /= 10;
    count++;
  }
  *pos = count;
  if (buffer[0] > 5 && buffer[0] < 9) {
    buffer[1] += 1;
  }
  if (buffer[0] == 9) {
    buffer[1] += 1;
    if (buffer[1] == 10) {
      buffer[1] = 0;
      buffer[2] += 1;
    }
  }
  if (spec->plus && minus == 0) {
    *str++ = '+';
    spec->width--;
  }
  if (minus) {
    if (spec->zero) {
      *str++ = '-';
      spec->width--;
    } else {
      spec->width--;
    }
  }
  if (spec->minus == 0) {
    for (int h = 6 + count; h <= spec->width; h++) {
      *str++ = spec->specifier;
    }
  }
  if (minus && spec->zero == 0) {
    *str++ = '-';
  }
  *str++ = (long long int)i + '0';
}
void e_zero(specificators spec, char *str) {
  if (spec.accurancy > 1) {
    char str_cpy[BUFFER] = {"0."};
    int zero_count = 2;
    while (zero_count < spec.accurancy + 2) {
      str_cpy[zero_count] = '0';
      zero_count++;
    }
    str_cpy[zero_count++] = spec.e_spec;
    str_cpy[zero_count++] = '+';
    str_cpy[zero_count++] = '0';
    str_cpy[zero_count++] = '0';
    if (spec.width) {
      int count_space = spec.width - 12;
      s21_memset(str, spec.specifier, count_space);
      str += s21_strlen(str);
    }
    s21_strcpy(str, str_cpy);
  } else {
    char str_cpy[BUFFER] = {"0e+00"};
    if (spec.e_spec == 'E') {
      str_cpy[1] = spec.e_spec;
    }
    if (spec.width) {
      int count_space = spec.width - 4;
      s21_memset(str, spec.specifier, count_space);
      str += s21_strlen(str);
    }
    s21_strcpy(str, str_cpy);
  }
}
void parser_f(specificators spec, char *str, va_list argument) {
  long double num;
  if (spec.length == 'L') {
    num = va_arg(argument, long double);
  } else {
    num = va_arg(argument, double);
  }
  f_to_str(spec, str, num);
}
void f_to_str(specificators spec, char *str, long double num) {
  long double num_copy, fractional;
  long long int whole_num = (long long int)num, num_count, minus = 0;
  char buffer[1024];
  if (spec.accurancy == 0) {
    spec.accurancy = 6;
  }
  if (spec.specifier == '0') {
    spec.zero = 1;
  }
  if (num < 0) {
    num *= -1;
    whole_num *= -1;
    minus = 1;
  }
  num_copy = modfl(num, &fractional);
  long long int t = num + 0.1;
  if (spec.accurancy < 4 && t == whole_num + 1 && spec.plus == 0 &&
      spec.minus == 0) {
    whole_num++;
  }
  for (int q = 0; q < spec.accurancy; q++) {
    num_copy *= 10.0;
  }
  if (spec.accurancy > -1) {
    num_copy = roundl(num_copy);
  } else {
    if (num_copy > 0.5) {
      num_copy = round(num);
    } else {
      num_copy = (long long int)num;
    }
  }
  if (spec.space && spec.plus == 0 && minus == 0) {
    *str++ = ' ';
    spec.width--;
  }
  if (minus == 0 && spec.plus) {
    if (spec.zero) {
      *str++ = '+';
      spec.width--;
    }
  }
  if (minus) {
    if (spec.zero) {
      *str++ = '-';
      spec.width--;
    }
  }
  if (minus && spec.accurancy > 0 && whole_num + 1 == num_copy * 10) {
    whole_num++;
  }
  num_count =
      float_write_to_array(spec, num, num_copy, whole_num, buffer, str, minus);
  if (num < 1 && -1 < num && (num == 0 || minus == 0)) {
    *str++ = '0';
  }
  for (num_count--; num_count >= 0; num_count--) {
    *str++ = buffer[num_count];
  }
}
int float_write_to_array(specificators spec, long double num,
                         long double num_copy, long long int whole_num,
                         char *buffer, char *str, int minus) {
  int digit, j = 0, num_count = 0;
  for (; j < spec.accurancy && spec.accurancy != -1; j++, num_count++) {
    digit = fmodl(num_copy, 10);
    buffer[num_count] = (char)('0' + digit);
    num_copy -= digit;
    num_copy /= 10;
  }
  if (spec.accurancy > 0) {
    buffer[num_count++] = '.';
    if (num < 1 && -1 < num && (spec.plus || spec.minus) && num != 0) {
      buffer[num_count++] = '1';
    }
    while (whole_num) {
      digit = whole_num % 10;
      buffer[num_count++] = (char)('0' + digit);
      whole_num -= digit;
      whole_num /= 10;
    }
  } else {
    if (spec.sharp) {
      buffer[num_count++] = '.';
    }
    while (num_copy >= 1) {
      digit = fmodl(roundl(num_copy), 10);
      buffer[num_count++] = digit + '0';
      num_copy -= digit;
      num_copy /= 10;
    }
  }
  if (minus && spec.zero == 0) {
    buffer[num_count++] = '-';
  }
  if (spec.zero == 0 && spec.plus && minus == 0) {
    buffer[num_count++] = '+';
  }
  if (spec.minus == 0) {
    for (whole_num = num_count; whole_num < spec.width;
         whole_num++, num_count++) {
      buffer[whole_num] = spec.specifier;
    }
  } else {
    char *str_copy = str + num_count;
    for (whole_num = num_count; whole_num < spec.width;
         whole_num++, str_copy++) {
      *str_copy = spec.specifier;
    }
  }
  return num_count;
}
void parser_g(specificators spec, char *str, va_list argument) {
  long double num;
  if (spec.length == 'L') {
    num = va_arg(argument, long double);
  } else {
    num = va_arg(argument, double);
  }
  if (spec.accurancy == 0 && num != 0) {
    spec.accurancy = 6;
  }
  g_to_str(spec, str, num);
  if (spec.e_spec == 'G') {
    to_upper(str);
  }
}
void g_to_str(specificators spec, char *str, long double num) {
  int accurancy = spec.accurancy, count = 0;
  long double num_cpy = num;
  while ((int)num_cpy != 0) {
    num_cpy /= 10;
    count++;
  }
  spec.accurancy -= count;
  if (count < 1) {
    spec.accurancy = 10;
  }
  if (num > 0.0001 && num != 0) {
    f_to_str(spec, str, num);
  } else {
    if (num != 0) {
      g_two_logic(str, num);
    } else {
      *str++ = '0';
    }
  }
  if (accurancy > -1) {
    s21_size_t len = s21_strlen(str) - 1;
    str += len;
    while (*str == '0' && num != 0) {
      *str = '\0';
      str--;
    }
  } else {
    str += 2;
    while (*str == '0') {
      str++;
    }
    str++;
    *str = '\0';
  }
}
void g_two_logic(char *str, long double num) {
  int e_count = 0;
  while (num < 1 && num != 0) {
    num *= 10;
    e_count++;
  }
  int num1 = round(num);
  *str++ = num1 + '0';
  *str++ = 'e';
  *str++ = '-';
  *(str + 1) = e_count % 10 + '0';
  e_count /= 10;
  *str++ = e_count % 10 + '0';
}
void parser_o(specificators spec, char *str, va_list argument) {
  int64_t num = va_arg(argument, int64_t);
  if (spec.sharp && num != 0 && spec.accurancy <= 0) {
    *str++ = '0';
  }
  if (spec.plus) {
    spec.plus = 0;
  }
  if (spec.space) {
    spec.space = 0;
  }
  int_to_str(spec, str, num, 8);
}
void parser_s(specificators spec, char *str, va_list argument) {
  if (spec.length == 'l') {
    wchar_t *c = va_arg(argument, wchar_t *);
    wchar_t_string_to_string(spec, str, c);
  } else {
    char *c = va_arg(argument, char *);
    string_to_string(spec, str, c);
  }
}
void wchar_t_string_to_string(specificators spec, char *str, wchar_t *c) {
  char buffer[BUFFER];
  wcstombs(buffer, c, BUFFER);
  if (spec.accurancy) {
    buffer[spec.accurancy] = '\0';
  }
  int a = s21_strlen(buffer);
  if (spec.minus) {
    wcstombs(str, c, BUFFER);
    s21_strcpy(str, buffer);
    str += a;
    for (int i = a; i < spec.width; i++, str++) {
      *str = spec.specifier;
    }
  } else {
    for (int i = a; i < spec.width; i++, str++) {
      *str = spec.specifier;
    }
    wcstombs(str, c, BUFFER);
    s21_strcpy(str, buffer);
  }
}
void string_to_string(specificators spec, char *str, char *c) {
  char buffer[BUFFER];
  s21_strcpy(buffer, c);
  if (spec.accurancy) {
    buffer[spec.accurancy] = '\0';
  }
  int a = s21_strlen(buffer);
  if (spec.accurancy < 0) {
    spec.width = a + spec.width;
  }
  if (spec.minus) {
    if (spec.accurancy != -2) {
      s21_strcpy(str, buffer);
    }
    str += a;
    for (int i = a; i < spec.width; i++, str++) {
      *str = spec.specifier;
    }
  } else {
    for (int i = a; i < spec.width; i++, str++) {
      *str = spec.specifier;
    }
    if (spec.accurancy >= 0) {
      s21_strcpy(str, buffer);
    }
  }
}
void parser_u(specificators spec, char *str, va_list argument) {
  uint64_t num = va_arg(argument, uint64_t);
  switch (spec.length) {
    case 'h':
      num = (uint16_t)num;
      break;
    case 'l':
      num = (uint64_t)num;
      break;
    case 0:
      num = (uint32_t)num;
  }
  uint_to_str(spec, str, num, 10);
}
void uint_to_str(specificators spec, char *str, unsigned long num, int base) {
  if (base != 0) {
    char buffer[1024];
    int num_count = 0;
    unsigned long num_copy = num;
    if (num_copy == 0 && spec.accurancy > -1) {
      buffer[num_count++] = '0';
    }
    if (num == 0 || base == 8) {
      spec.sharp = 0;
    }
    if (spec.plus) {
      spec.plus = 0;
    }
    while (num) {
      int digit = num % base;
      buffer[num_count++] = "0123456789abcdef"[digit];
      num -= digit;
      num /= base;
    }
    if (spec.specifier == '0' || spec.accurancy > 0) {
      spec.zero = 1;
    }
    int_write_to_array(spec, num_count, str, buffer, 0);
  }
}
void parser_x(specificators spec, char *str, va_list argument) {
  uint64_t num = va_arg(argument, uint64_t);
  switch (spec.length) {
    case 'h':
      num = (uint16_t)num;
      break;
    case 'l':
      num = (uint64_t)num;
      break;
    case 0:
      num = (uint32_t)num;
  }
  uint_to_str(spec, str, num, 16);
  if (spec.e_spec == 'X') {
    to_upper(str);
  }
}
void to_upper(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') {
      *str = *str - 'a' + 'A';
    }
    str++;
  }
}
void p_to_str(void *ptr, char *str, specificators spec) {
  uintptr_t num = (uintptr_t)ptr;
  char buffer[1024];
  int i = 0, g = 0;
  if (num == 0 && spec.accurancy != -2) {
    buffer[i] = '0';
    i = 1;
  } else {
    while (num != 0) {
      int digit = num % 16;
      if (digit < 10) {
        buffer[i] = (char)('0' + digit);
      } else {
        buffer[i] = (char)('a' + digit - 10);
      }
      num /= 16;
      i++;
    }
  }
  if (spec.accurancy > 0) {
    while (i < spec.accurancy) {
      buffer[i++] = '0';
    }
  }
  buffer[i++] = 'x';
  buffer[i++] = '0';
  if (spec.minus == 0) {
    for (g = i; g < spec.width; g++) {
      buffer[g] = spec.specifier;
      i++;
    }
  } else {
    char *str_copy = str + i;
    for (g = i; g < spec.width; g++) {
      *str_copy++ = spec.specifier;
    }
  }
  for (i--; i >= 0; i--, str++) {
    *str = buffer[i];
  }
}
void n_to_str(const char *str, const char *str2, va_list argument) {
  int *c = va_arg(argument, int *);
  *c = str - str2;
}
