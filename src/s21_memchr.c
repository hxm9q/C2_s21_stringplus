#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = str;
  void *result = S21_NULL;
  s21_size_t i = 0;

  while (i < n && s) {
    if (*s == (char)c) {
      result = (void *)s;
      break;
    }
    s++;
    i++;
  }

  return result;
}