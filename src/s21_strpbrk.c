#include "s21_string.h"

const char *s21_strpbrk(const char *str1, const char *str2) {
  const char *result = S21_NULL;
  s21_size_t i;
  s21_size_t j;

  for (i = 0; i < s21_strlen(str1); i++) {
    for (j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        result = &str1[i];
        j = s21_strlen(str2);
        i = s21_strlen(str1);
      }
    }
  }
  return result;
}