#include "s21_tests.h"

START_TEST(s21_strncmp_test) {
  char test1[] = "This is the Way";
  char test2[] = "Grogu";
  char test3[] = "Grogu\0";
  char test4[] = "";
  char test5[] = "";

  ck_assert_int_eq(s21_strncmp(test1, test2, 5) == 0,
                   strncmp(test1, test2, 5) == 0);
  ck_assert_int_eq(s21_strncmp(test1, test2, 6) > 0,
                   strncmp(test1, test2, 6) > 0);
  ck_assert_int_eq(s21_strncmp(test2, test3, 6) == 0,
                   strncmp(test2, test3, 6) == 0);
  ck_assert_int_eq(s21_strncmp(test1, test3, 10) < 0,
                   strncmp(test1, test3, 10) < 0);
  ck_assert_int_eq(s21_strncmp(test4, test5, 1) == 0,
                   strncmp(test4, test5, 1) == 0);
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s = suite_create("suite_strncmp");
  TCase *tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, s21_strncmp_test);

  suite_add_tcase(s, tc);
  return s;
}