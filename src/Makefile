CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g

all: clean s21_string.a test gcov_report

test:
	$(CC) $(CFLAGS) --coverage Tests/*.c *.c -o test -lcheck -lm
	./test

s21_string.a:
	$(CC) $(CFLAGS) *.c -c
	ar rc s21_string.a *.o
	ranlib s21_string.a

gcov_report:
	lcov -t "s21_string_test" -o fizzbuzz.info -c -d .
	genhtml -o report fizzbuzz.info
	open -a "Google Chrome" report/src/index.html

style: clean
	clang-format -style=Google -i *.c *.h tests/*.c tests/*.h

clean:
	@-rm -rf *.o && rm -rf *.gcno test.dSYM/
	@-rm -rf *.a && rm -rf *.gcda
	@-rm -rf *.info && rm -rf *.gcov
	@-rm -rf ./test && rm -rf ./gcov_report
	@-rm -rf ./report/
	@-rm -rf s21_test main