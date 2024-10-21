#include "s21_tests.h"

START_TEST(s21_strncat_test) {
  char test1[50] = "This is";
  char test2[50] = "This is";
  char test3[50] = " daWay";
  char test4[50] = "";
  char test5[50] = "";
  char test6[50] = "";

  ck_assert_str_eq(s21_strncat(test1, test3, sizeof(test2) - strlen(test1)),
                   strncat(test1, test3, sizeof(test2) - strlen(test1)));
  ck_assert_str_eq(s21_strncat(test4, test5, sizeof(test6) - strlen(test4)),
                   strncat(test4, test5, sizeof(test6) - strlen(test4)));
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s = suite_create("suite_strncat");
  TCase *tc = tcase_create("strncat_tc");

  tcase_add_test(tc, s21_strncat_test);

  suite_add_tcase(s, tc);
  return s;
}