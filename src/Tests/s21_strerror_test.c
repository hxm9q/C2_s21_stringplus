#include "s21_tests.h"

START_TEST(s21_strerror_test) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  ck_assert_str_eq(s21_strerror(-1), strerror(-1));
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s = suite_create("suite_strerror");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, s21_strerror_test);

  suite_add_tcase(s, tc);
  return s;
}