#include "s21_tests.h"

START_TEST(s21_insert_test1) {
  char str1[] = "Lorem ipsum dolor sit amet";
  char str2[] = "vestibulum odio lectus";

  char *str = s21_insert(str1, str2, 2);
  ck_assert_str_eq(str, "Lovestibulum odio lectusrem ipsum dolor sit amet");
  free(str);
}
END_TEST

START_TEST(s21_insert_test2) {
  char str3[] = "consectetur adipiscing elit";
  char str4[] = "s";

  char *str = s21_insert(str3, str4, 5);
  ck_assert_str_eq(str, "consesctetur adipiscing elit");
  free(str);
}
END_TEST

START_TEST(s21_insert_test3) {
  char str5[] = "";
  char *str = s21_insert(str5, "s", 0);
  ck_assert_str_eq(str, "s");
  free(str);
}
END_TEST

START_TEST(s21_insert_str_null) {
  char str4[] = "s";
  char *str = s21_insert(NULL, str4, 5);
  ck_assert_ptr_eq(str, NULL);
  if (str != NULL) {
    free(str);
  }

  char str3[] = "consectetur adipiscing elit";
  str = s21_insert(str3, NULL, 5);
  ck_assert_ptr_eq(str, NULL);
  if (str != NULL) {
    free(str);
  }

  str = s21_insert(NULL, NULL, 5);
  ck_assert_ptr_eq(str, NULL);
  if (str != NULL) {
    free(str);
  }
}
END_TEST

Suite *insert_suite(void) {
  Suite *s = suite_create("s21_insert");
  TCase *tc = tcase_create("to_insert_tc");

  tcase_add_test(tc, s21_insert_test1);
  tcase_add_test(tc, s21_insert_test2);
  tcase_add_test(tc, s21_insert_test3);
  tcase_add_test(tc, s21_insert_str_null);

  suite_add_tcase(s, tc);
  return s;
}