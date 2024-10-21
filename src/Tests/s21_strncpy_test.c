#include "s21_tests.h"

START_TEST(s21_strncpy_test) {
  char test1[] = "This is the Way";
  char test2[] = "";
  char test3[] = "\0";
  char test4[] = "Blablabla";

  ck_assert_str_eq(s21_strncpy(test1, test2, 5), strncpy(test1, test2, 5));
  ck_assert_str_eq(s21_strncpy(test2, test3, 1), strncpy(test2, test3, 1));
  ck_assert_str_eq(s21_strncpy(test1, test4, 10), strncpy(test1, test4, 10));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s = suite_create("suite_strncpy");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, s21_strncpy_test);

  suite_add_tcase(s, tc);
  return s;
}