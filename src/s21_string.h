#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_size_t unsigned long long
#define BUFFER 1024
#define S21_NULL (void *)0

int s21_sprintf(char *str, const char *format, ...);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strerror(int errnum);
char *s21_strtok(char *str, const char *delim);
s21_size_t s21_strspn(const char *str, const char *delim);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
const char *s21_strpbrk(const char *str1, const char *str2);

typedef struct {
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int hash;
  int width;
  int accurancy;
  char specifier;
  char length;
  char e_spec;
  int accurancy_copy;
} specificators;

int parser_spec(const char format);
const char *parser_flags(specificators *spec, const char *format);
const char *parser_width(specificators *spec, const char *format,
                         va_list argument);
const char *parser_accurancy(specificators *spec, const char *format,
                             va_list argument);
const char *parser_length(specificators *spec, const char *format);
void main_parser(char format, char *buffer, specificators spec,
                 va_list argument, char *str_start, char *str);
void parser_c(specificators spec, char *str, va_list argument);
void char_to_string(specificators spec, char *str, char c);
void parser_int(specificators spec, char *str, va_list argument);
void int_to_str(specificators spec, char *str, int64_t num, int base);
void handle_length_modifier(specificators spec, int64_t *num);
void int_write_to_array(specificators spec, int num_count, char *str,
                        char *buffer, int minus);
void parser_e(specificators spec, char *str, va_list argument);
void e_to_str(specificators spec, char *str, long double num);
void e_logic(specificators *spec, long double num, char *str, int *pos,
             int *e_count, int *buffer, int minus);
void e_zero(specificators spec, char *str);
void parser_f(specificators spec, char *str, va_list argument);
void f_to_str(specificators spec, char *str, long double num);
int float_write_to_array(specificators spec, long double num,
                         long double num_copy, long long int whole_num,
                         char *buffer, char *str, int minus);
void parser_g(specificators spec, char *str, va_list argument);
void g_to_str(specificators spec, char *str, long double num);
void g_two_logic(char *str, long double num);
void parser_o(specificators spec, char *str, va_list argument);
void o_to_string(int64_t num, char *str, specificators spec);
void parser_s(specificators spec, char *str, va_list argument);
void wchar_t_string_to_string(specificators spec, char *str, wchar_t *c);
void string_to_string(specificators spec, char *str, char *c);
void parser_u(specificators spec, char *str, va_list argument);
void uint_to_str(specificators spec, char *str, unsigned long num, int base);
void to_upper(char *str);
void parser_x(specificators spec, char *str, va_list argument);
void x_to_string(int64_t num, char *str, specificators spec);
void p_to_str(void *ptr, char *str, specificators spec);
void n_to_str(const char *str, const char *str2, va_list argument);

#endif
