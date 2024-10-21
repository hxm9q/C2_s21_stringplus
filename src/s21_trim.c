#include "s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  if (src == NULL || trim_chars == NULL) {
    return NULL;
  }

  size_t src_len = s21_strlen(src);

  s21_size_t start_pos = 0;
  while (start_pos < src_len &&
         s21_strchr(trim_chars, src[start_pos]) != NULL) {
    start_pos++;
  }

  size_t end_pos = src_len - 1;
  while (end_pos > start_pos && s21_strchr(trim_chars, src[end_pos]) != NULL) {
    end_pos--;
  }

  if (start_pos > end_pos) {
    char* result = malloc(1);
    result[0] = '\0';
    return result;
  }

  size_t trimmed_len = end_pos - start_pos + 1;

  char* result = malloc(trimmed_len + 1);

  s21_strncpy(result, src + start_pos, trimmed_len);
  result[trimmed_len] = '\0';

  return result;
}
