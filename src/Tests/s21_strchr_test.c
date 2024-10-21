#include "s21_tests.h"

START_TEST(s21_strchr_test) {
  char test1[] = "Bulk";
  char test2[] = "Bulk";
  char test3[] = "Giberrish";

  ck_assert_str_eq(s21_strchr(test1, 'u'), "ulk");
  ck_assert_str_eq(s21_strchr(test2, 'u'), strchr(test2, 'u'));
  ck_assert_str_eq(s21_strchr(test3, '\0'), strchr(test3, '\0'));
  const char *str = "abcdef";
  char target = 'z';
  char *result = strchr(str, target);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s = suite_create("suite_strchr");
  TCase *tc = tcase_create("strchr_tc");

  tcase_add_test(tc, s21_strchr_test);

  suite_add_tcase(s, tc);
  return s;
}