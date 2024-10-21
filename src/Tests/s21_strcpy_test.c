#include "s21_tests.h"

START_TEST(s21_strcpy_test) {
  char test1[] = "This is da way according to our Code";
  char test2[] = "     ";
  char test3[] = "Mgupp\0";
  char test4[] = "rept\0Codem";
  char test5[128] = "";
  char test6[] = "May the force be with you";
  char test7[] = "";
  char test8[] = "1";

  ck_assert_str_eq(s21_strcpy(test1, test2), strcpy(test1, test2));
  ck_assert_str_eq(s21_strcpy(test2, test3), strcpy(test2, test3));
  ck_assert_str_eq(s21_strcpy(test4, test5), strcpy(test4, test5));
  ck_assert_str_eq(s21_strcpy(test5, test4), strcpy(test5, test4));
  ck_assert_str_eq(s21_strcpy(test6, test5), strcpy(test6, test5));
  ck_assert_str_eq(s21_strcpy(test7, test5), strcpy(test7, test5));
  ck_assert_str_eq(s21_strcpy(test8, test5), strcpy(test8, test5));
}
END_TEST

Suite *strcpy_suite(void) {
  Suite *s = suite_create("suite_strcpy");
  TCase *tc = tcase_create("strcpy_tc");

  tcase_add_test(tc, s21_strcpy_test);

  suite_add_tcase(s, tc);
  return s;
}