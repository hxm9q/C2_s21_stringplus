#include "s21_tests.h"

START_TEST(s21_strlen_test) {
  char test1[] = "ThisisDaway";
  char test2[] = "Grogu";
  char test3[] = "1\0";
  char test4[] = " ";
  char test5[] = "1234\05678";
  char test6[] = "fbd\\\\0";
  char test7[] = "";
  char test8[] = "1";

  ck_assert_int_eq(s21_strlen(test1), strlen(test1));
  ck_assert_int_eq(s21_strlen(test2), strlen(test2));
  ck_assert_int_eq(s21_strlen(test3), strlen(test3));
  ck_assert_int_eq(s21_strlen(test4), strlen(test4));
  ck_assert_int_eq(s21_strlen(test5), strlen(test5));
  ck_assert_int_eq(s21_strlen(test6), strlen(test6));
  ck_assert_int_eq(s21_strlen(test7), strlen(test7));
  ck_assert_int_eq(s21_strlen(test8), strlen(test8));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s = suite_create("suite_strlen");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, s21_strlen_test);

  suite_add_tcase(s, tc);
  return s;
}