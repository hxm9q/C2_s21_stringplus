#include "s21_tests.h"

START_TEST(s21_memchr_test) {
  char test1[] = "ThisisDaway";
  char test2 = 'D';
  char test3 = 'h';
  char test4[] = "4324/\0";
  char test5[] = "?";
  char test6 = 'g';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';

  ck_assert_ptr_eq(s21_memchr(test1, test2, 10), memchr(test1, test2, 10));
  ck_assert_ptr_eq(s21_memchr(test1, test3, 10), memchr(test1, test3, 10));
  ck_assert_ptr_eq(s21_memchr(test4, test6, 7), memchr(test4, test6, 7));
  ck_assert_ptr_eq(s21_memchr(test5, test7, 1), memchr(test5, test7, 1));
  ck_assert_ptr_eq(s21_memchr(test4, test8, 7), memchr(test4, test8, 7));
  ck_assert_ptr_eq(s21_memchr(test4, test9, 7), memchr(test4, test9, 7));
}
END_TEST;

Suite *memchr_suite(void) {
  Suite *s = suite_create("suite_memchr");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, s21_memchr_test);

  suite_add_tcase(s, tc);
  return s;
}