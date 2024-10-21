#include "s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }
  s21_size_t length = s21_strlen(str);
  char *result = (char *)malloc(length + 1);

  if (result == S21_NULL) {
    return S21_NULL;
  }

  for (s21_size_t i = 0; i <= length; i++) {
    result[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
  }
  result[length] = '\0';
  return result;
}
