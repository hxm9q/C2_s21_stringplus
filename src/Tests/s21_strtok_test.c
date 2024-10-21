#include "s21_tests.h"

START_TEST(s21_strtok_test) {
  char test1[] = "This is the Way";
  char test2[] = "This is the Way";
  char test3[] = "y";
  char test4[] = "";
  char test5[] = "";
  char test6[] = "\0";
  char test7[] = "\0This is the Way";
  char test8[] = "0\0";
  char *test9 = S21_NULL;

  ck_assert_pstr_eq(s21_strtok(test1, test3), strtok(test1, test3));
  ck_assert_pstr_eq(s21_strtok(test1, test2), strtok(test1, test2));
  ck_assert_pstr_eq(s21_strtok(test4, test5), strtok(test4, test5));
  ck_assert_pstr_eq(s21_strtok(test1, test6), strtok(test1, test6));
  ck_assert_pstr_eq(s21_strtok(test7, test4), strtok(test7, test4));
  ck_assert_pstr_eq(s21_strtok(test7, test6), strtok(test7, test6));
  ck_assert_pstr_eq(s21_strtok(test7, test8), strtok(test7, test8));
  ck_assert_pstr_eq(s21_strtok(test9, test5), strtok(test9, test5));
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("suite_strtok");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, s21_strtok_test);

  suite_add_tcase(s, tc);
  return s;
}