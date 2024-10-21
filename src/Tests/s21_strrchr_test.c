#include "s21_tests.h"

START_TEST(s21_strrchr_test) {
  char test[] = "This is the Way";
  int ch1 = 'w';
  int ch2 = '\0';
  int ch3 = 'e';
  int ch4 = 'a';
  int ch5 = 's';
  int ch6 = '0';

  ck_assert_pstr_eq(s21_strrchr(test, ch1), strrchr(test, ch1));
  ck_assert_pstr_eq(s21_strrchr(test, ch2), strrchr(test, ch2));
  ck_assert_pstr_eq(s21_strrchr(test, ch3), strrchr(test, ch3));
  ck_assert_pstr_eq(s21_strrchr(test, ch4), strrchr(test, ch4));
  ck_assert_pstr_eq(s21_strrchr(test, ch5), strrchr(test, ch5));
  ck_assert_pstr_eq(s21_strrchr(test, ch6), strrchr(test, ch6));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("suite_strrchr");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, s21_strrchr_test);

  suite_add_tcase(s, tc);
  return s;
}