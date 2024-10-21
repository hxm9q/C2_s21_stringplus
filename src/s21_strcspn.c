#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int flag = 1;
  s21_size_t i = 0;
  s21_size_t j = 0;

  while (i < s21_strlen(str1) && flag) {
    while (j < s21_strlen(str2)) {
      if (str1[i] == str2[j]) {
        flag = 0;
        break;
      }
      j++;
    }
    if (flag == 1) {
      len++;
    }
    i++;
  }
  return len;
}