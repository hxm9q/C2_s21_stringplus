#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    s21_size_t i = 0;
    for (; i <= s21_strlen(haystack) - s21_strlen(needle); i++) {
      s21_size_t j = 0;
      for (; j < s21_strlen(needle); j++) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == s21_strlen(needle)) {
        return (char *)&haystack[i];
      }
    }
  } else {
    return S21_NULL;
  }
  return S21_NULL;
}