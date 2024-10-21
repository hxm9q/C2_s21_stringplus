#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  int i = s21_strlen(str);

  while (i >= 0) {
    if (str[i] == c) {
      return (char *)str + i;
    }
    i--;
  }

  return S21_NULL;
}