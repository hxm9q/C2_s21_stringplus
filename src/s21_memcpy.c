#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *result = dest;
  const unsigned char *s = src;
  s21_size_t i = 0;

  for (; i < n; i++) {
    result[i] = s[i];
  }
  return dest;
}