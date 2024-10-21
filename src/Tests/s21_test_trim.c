#include "s21_tests.h"

START_TEST(s21_trim_test1) {
  char str1[] = "   Lorem ipsum dolor sit amet   ";
  char *str = s21_trim(str1, " ");
  ck_assert_str_eq(str, "Lorem ipsum dolor sit amet");
  free(str);
}
END_TEST

START_TEST(s21_trim_test2) {
  char str1[] = "-----aaaa---------";
  char *str = s21_trim(str1, "-");
  ck_assert_str_eq(str, "aaaa");
  free(str);
}
END_TEST

START_TEST(s21_trim_test3) {
  char str1[] = "---bbbb-bbb------";
  char *str = s21_trim(str1, "-");
  ck_assert_str_eq(str, "bbbb-bbb");
  free(str);
}
END_TEST

START_TEST(s21_trim_test4) {
  char str1[] = "----";
  char *str = s21_trim(str1, "-");
  ck_assert_str_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_trim_str_null) {
  char *str = s21_trim(S21_NULL, " ");
  ck_assert_ptr_eq(str, S21_NULL);
  if (str != S21_NULL) {
    free(str);
  }

  char str3[] = "consectetur adipiscing elit";
  str = s21_trim(str3, NULL);
  ck_assert_ptr_eq(str, S21_NULL);
  if (str != S21_NULL) {
    free(str);
  }

  str = s21_trim(S21_NULL, S21_NULL);
  ck_assert_ptr_eq(str, S21_NULL);
  if (str != S21_NULL) {
    free(str);
  }
}
END_TEST

Suite *trim_suite(void) {
  Suite *s = suite_create("s21_trim");
  TCase *tc = tcase_create("to_trim_tc");
  tcase_add_test(tc, s21_trim_test1);
  tcase_add_test(tc, s21_trim_test2);
  tcase_add_test(tc, s21_trim_test3);
  tcase_add_test(tc, s21_trim_test4);
  tcase_add_test(tc, s21_trim_str_null);

  suite_add_tcase(s, tc);
  return s;
}