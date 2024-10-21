#include "s21_tests.h"

START_TEST(s21_strstr_test) {
  char test1[] = "This is the Way";
  char test2[] = "This is the Way";
  char test3[] = "Way";
  char test4[] = "This is da way";
  char test5[] = "";
  char test6[] = "";

  ck_assert_pstr_eq(s21_strstr(test1, test2), strstr(test1, test2));
  ck_assert_pstr_eq(s21_strstr(test1, test3), strstr(test1, test3));
  ck_assert_pstr_eq(s21_strstr(test1, test4), strstr(test1, test4));
  ck_assert_pstr_eq(s21_strstr(test1, test2), strstr(test1, test2));
  ck_assert_pstr_eq(s21_strstr(test5, test6), strstr(test5, test6));
  ck_assert_pstr_eq(s21_strstr(test5, test1), strstr(test5, test1));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("suite_strstr");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, s21_strstr_test);

  suite_add_tcase(s, tc);
  return s;
}