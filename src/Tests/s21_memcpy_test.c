#include "s21_tests.h"

START_TEST(s21_memcpy_test) {
  char test1[BUFFER] = "Thisis theway";
  char test2[BUFFER] = "  ";
  char test3[BUFFER] = "///  ";
  char test4[BUFFER] = "   & ///";
  char test5[BUFFER] = "";
  char test6[BUFFER] = "8922486";
  char test7[BUFFER] = "5526\0123";
  char test8[BUFFER] = "";
  char test9[BUFFER] = "";
  char test10[BUFFER] = "1";
  char test11[BUFFER] = "1";

  ck_assert_str_eq(s21_memcpy(test1, test2, 2), memcpy(test1, test2, 2));
  ck_assert_str_eq(s21_memcpy(test3, test4, 6), memcpy(test3, test4, 6));
  ck_assert_str_eq(s21_memcpy(test5, test6, 4), memcpy(test5, test6, 4));
  ck_assert_str_eq(s21_memcpy(test6, test7, 4), memcpy(test6, test7, 4));
  ck_assert_str_eq(s21_memcpy(test8, test9, 1), memcpy(test8, test9, 1));
  ck_assert_str_eq(s21_memcpy(test10, test11, 1), memcpy(test10, test11, 1));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s = suite_create("suite_memcpy");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, s21_memcpy_test);

  suite_add_tcase(s, tc);
  return s;
}