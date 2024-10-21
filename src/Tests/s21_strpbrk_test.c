#include "s21_tests.h"

START_TEST(s21_strpbrk_test) {
  char test1[] = "This is the Way";
  char test2[] = "is the W";
  char test3[] = "Th";
  char test4[] = "";
  char test5[] = "\0";

  ck_assert_pstr_eq(s21_strpbrk(test1, test2), strpbrk(test1, test2));
  ck_assert_pstr_eq(s21_strpbrk(test4, test3), strpbrk(test4, test3));
  ck_assert_pstr_eq(s21_strpbrk(test5, test4), strpbrk(test5, test4));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s = suite_create("suite_strpbrk");
  TCase *tc = tcase_create("strpbrk_tc");

  tcase_add_test(tc, s21_strpbrk_test);

  suite_add_tcase(s, tc);
  return s;
}