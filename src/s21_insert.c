#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (str == S21_NULL || src == S21_NULL) {
    return S21_NULL;
  }

  char *result = (char *)malloc(s21_strlen(src) + s21_strlen(str) + 1);
  if (result == S21_NULL) {
    return S21_NULL;
  }

  s21_strncpy(result, src, start_index);
  result[start_index] = '\0';

  s21_strncat(result, str, s21_strlen(str));
  s21_strncat(result, src + start_index, s21_strlen(src) - start_index);

  return result;
}