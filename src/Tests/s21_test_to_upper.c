#include "s21_tests.h"

START_TEST(s21_to_upper_test1) {
  char str1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
  char *str = s21_to_upper(str1);
  ck_assert_str_eq(str,
                   "LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT");
  free(str);
}
END_TEST

START_TEST(s21_to_upper_test2) {
  char str2[] = "vestibulum odio lectus";
  char *str = s21_to_upper(str2);
  ck_assert_str_eq(str, "VESTIBULUM ODIO LECTUS");
  free(str);
}
END_TEST

START_TEST(s21_to_upper_test3) {
  char str3[] = "";
  char *str = s21_to_upper(str3);
  ck_assert_str_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_to_upper_test4) {
  char str4[] = "s";
  char *str = s21_to_upper(str4);
  ck_assert_str_eq(str, "S");
  free(str);
}
END_TEST

START_TEST(s21_to_upper_str_null) {
  char *str = s21_to_upper(S21_NULL);
  ck_assert_ptr_eq(str, S21_NULL);
  if (str != S21_NULL) {
    free(str);
  }
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc = tcase_create("to_upper_tc");

  tcase_add_test(tc, s21_to_upper_test1);
  tcase_add_test(tc, s21_to_upper_test2);
  tcase_add_test(tc, s21_to_upper_test3);
  tcase_add_test(tc, s21_to_upper_test4);
  tcase_add_test(tc, s21_to_upper_str_null);
  suite_add_tcase(s, tc);
  return s;
}