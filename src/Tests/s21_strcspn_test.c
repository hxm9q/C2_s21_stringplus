#include "s21_tests.h"

START_TEST(s21_strcspn_test) {
  char test1[] = "MaydaForcebewithYou";
  char test2[] = "MaydaForce";
  char test3[] = "ThisisDaWay";
  char test5[] = "0/";

  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s = suite_create("suite_strcspn");
  TCase *tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, s21_strcspn_test);

  suite_add_tcase(s, tc);
  return s;
}