#include "s21_tests.h"

int main() {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner *sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

void run_tests() {
  Suite *list_cases[] = {
      memchr_suite(),   memcmp_suite(),   memcpy_suite(),  memset_suite(),
      strchr_suite(),   strcpy_suite(),   strcspn_suite(), strerror_suite(),
      strlen_suite(),   strncat_suite(),  strncmp_suite(), strncpy_suite(),
      strpbrk_suite(),  strrchr_suite(),  strstr_suite(),  strtok_suite(),

      to_upper_suite(), to_lower_suite(), trim_suite(),    insert_suite(),
      sprintf_suite(),  sscanf_suite(),   S21_NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != S21_NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
}