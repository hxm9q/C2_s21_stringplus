#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *next_token = S21_NULL;

  if (str) {
    next_token = str;
    while (*next_token && s21_strchr(delim, *next_token)) *next_token++ = '\0';
  }

  if (next_token != S21_NULL) {
    if (*next_token != '\0') {
      str = next_token;
      while (*next_token && !s21_strchr(delim, *next_token)) next_token++;
      while (*next_token && s21_strchr(delim, *next_token))
        *next_token++ = '\0';
    } else {
      str = S21_NULL;
    }
  }
  return str;
}