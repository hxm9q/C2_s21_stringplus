#include "s21_tests.h"

START_TEST(s21_memcmp_test) {
  char test1[] = "This is da Way";
  char test2[] = "This is the Way";
  char test3[] = "\0";
  char test4[] = "Yota\0 atoy";
  char test5[] = "Yota\0 atoy";
  char test6[] = "";
  char test7[] = "";
  char test8[] = "1";
  char test9[] = "1";

  ck_assert_int_eq(s21_memcmp(test1, test2, 14), memcmp(test1, test2, 14));
  ck_assert_int_eq(s21_memcmp(test1, test3, 2), memcmp(test1, test3, 2));
  ck_assert_int_eq(s21_memcmp(test2, test3, 2), memcmp(test2, test3, 2));
  ck_assert_int_eq(s21_memcmp(test4, test1, 9), memcmp(test4, test1, 9));
  ck_assert_int_eq(s21_memcmp(test4, test5, 7), memcmp(test4, test5, 7));
  ck_assert_int_eq(s21_memcmp(test6, test7, 1), memcmp(test6, test7, 1));
  ck_assert_int_eq(s21_memcmp(test8, test9, 1), memcmp(test8, test9, 1));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s = suite_create("suite_memcmp");
  TCase *tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, s21_memcmp_test);

  suite_add_tcase(s, tc);
  return s;
}