#ifndef C2_S21_STRINGPLUS_3_S21_SSCANF_H
#define C2_S21_STRINGPLUS_3_S21_SSCANF_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define s21_BF_SIZE 1024

typedef struct {
  int minus;
  int width;
  int length;
  char specifier;
  int star;
  int success;
  int n_flag;
} scan_spec;

int s21_sscanf(const char *str, const char *format, ...);

void integer_flags(va_list *argument, const char **str, const char *start_str,
                   scan_spec *spec);
long int oct_hex_flags(const char **str, const char *start_str,
                       scan_spec *spec);
void float_flags(va_list *argument, const char **str, scan_spec *spec);

const char *pars_width(const char *format, scan_spec *spec);
const char *pars_length(const char *format, scan_spec *spec);
const char *pars_star(const char *format, scan_spec *spec);
const char *pars_spec(const char *format, scan_spec *spec);

int pars_minus(const char *str, scan_spec *spec);
long int decimal(const char **str, const char *start_str, scan_spec *spec);
long int octal(const char **str, const char *start_str, scan_spec *spec);
long int hexadecimal(const char **str, const char *start_str, scan_spec *spec);
void hexadecimal_pointer(const char **str, const char *start_str,
                         void **pointer, scan_spec *spec);
void length_longdouble(va_list *argument, const char **str, scan_spec *spec);
void length_float(va_list *argument, const char **str, scan_spec *spec);
char *get_float_str(const char **str, scan_spec *spec);
void s_flag(va_list *argument, const char **str, scan_spec *spec);

#endif  // C2_S21_STRINGPLUS_3_S21_SSCANF_H
