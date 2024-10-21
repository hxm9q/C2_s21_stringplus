#include "s21_tests.h"

START_TEST(s21_to_lower_test1) {
  char str1[] = "LOREM IPSUM DOLOR SIT AMET, CONSECTETUR ADIPISCING ELIT";
  char *str = s21_to_lower(str1);
  ck_assert_str_eq(str,
                   "lorem ipsum dolor sit amet, consectetur adipiscing elit");
  free(str);
}
END_TEST

START_TEST(s21_to_lower_test2) {
  char str2[] = "VESTIBULUM ODIO LECTUS";
  char *str = s21_to_lower(str2);
  ck_assert_str_eq(str, "vestibulum odio lectus");
  free(str);
}
END_TEST

START_TEST(s21_to_lower_test3) {
  char str3[] = "";
  char *str = s21_to_lower(str3);
  ck_assert_str_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_to_lower_test4) {
  char str4[] = "A";
  char *str = s21_to_lower(str4);
  ck_assert_str_eq(str, "a");
  free(str);
}
END_TEST

START_TEST(s21_to_lower_str_null) {
  char *str = s21_to_lower(S21_NULL);
  ck_assert_ptr_eq(str, S21_NULL);
  if (str != S21_NULL) {
    free(str);
  }
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc = tcase_create("to_lower_tc");

  tcase_add_test(tc, s21_to_lower_test1);
  tcase_add_test(tc, s21_to_lower_test2);
  tcase_add_test(tc, s21_to_lower_test3);
  tcase_add_test(tc, s21_to_lower_test4);
  tcase_add_test(tc, s21_to_lower_str_null);

  suite_add_tcase(s, tc);
  return s;
}