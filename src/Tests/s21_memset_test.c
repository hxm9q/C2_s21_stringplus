#include "s21_tests.h"

START_TEST(s21_memset_test) {
  char test1[] = "123456789";

  ck_assert_str_eq(s21_memset(test1, 'a', 9), memset(test1, 'a', 9));
  ck_assert_str_eq(s21_memset(test1, '2', 3), memset(test1, '2', 3));
  ck_assert_str_eq(s21_memset(test1, '5', 4), memset(test1, '5', 4));
}
END_TEST

Suite *memset_suite(void) {
  Suite *s = suite_create("suite_memset");
  TCase *tc = tcase_create("memset_tc");

  tcase_add_test(tc, s21_memset_test);

  suite_add_tcase(s, tc);
  return s;
}