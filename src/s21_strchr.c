#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  int i = 0;

  while (str[i] && str[i] != c) {
    i++;
  }

  if (c == str[i]) {
    return (char *)str + i;
  } else {
    return S21_NULL;
  }
}