#include "s21_sscanf_tests.h"

//Тесты спецификатора "%c"
START_TEST(sscanf_test_c_1) {
  char str[] = "1";
  char format[] = "%c";
  char c1, c2;

  int original_result = sscanf(str, format, &c1);
  int my_result = s21_sscanf(str, format, &c2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_c_2) {
  char str[] = "%a";
  char format[] = "%%%c";
  char c1, c2;

  int original_result = sscanf(str, format, &c1);
  int my_result = s21_sscanf(str, format, &c2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_test_c_3) {
  char str[] = "123";
  char format[] = "%c%c%c";
  char c11, c12, c13, c21, c22, c23;

  int original_result = sscanf(str, format, &c11, &c12, &c13);
  int my_result = s21_sscanf(str, format, &c21, &c22, &c23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_c_4) {
  char str[] = "123";
  char format[] = "%c %c \t%c";
  char c11, c12, c13, c21, c22, c23;

  int original_result = sscanf(str, format, &c11, &c12, &c13);
  int my_result = s21_sscanf(str, format, &c21, &c22, &c23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_test_c_5) {
  char str[] = "1  2 3";
  char format[] = "%c %c \t%c";
  char c11, c12, c13, c21, c22, c23;

  int original_result = sscanf(str, format, &c11, &c12, &c13);
  int my_result = s21_sscanf(str, format, &c21, &c22, &c23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

//Тесты спецификатора "%d"

START_TEST(sscanf_test_d_1) {
  char str[] = "1";
  char format[] = "%d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_2) {
  char str[] = "-1";
  char format[] = "%d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_3) {
  char str[] = "123";
  char format[] = "%d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_4) {
  char str[] = "+123";
  char format[] = "%d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_5) {
  char str[] = "-123";
  char format[] = "%d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_6) {
  char str[] = "123";
  char format[] = "%d%d%d";
  int d11 = 0, d21 = 0;
  int d12 = 0, d22 = 0;
  int d13 = 0, d23 = 0;

  int original_result = sscanf(str, format, &d11, &d12, &d13);
  int my_result = s21_sscanf(str, format, &d21, &d22, &d23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(d12, d22);
  ck_assert_int_eq(d13, d23);
}
END_TEST
START_TEST(sscanf_test_d_7) {
  char str[] = "123";
  char format[] = "%3d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_8) {
  char str[] = "-123";
  char format[] = "%3d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_d_9) {
  char str[] = "-123";
  char format[] = "%10d";
  int d1, d2;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_hd_1) {
  char str[] = "123";
  char format[] = "%hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_2) {
  char str[] = "+123";
  char format[] = "%hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_3) {
  char str[] = "-123";
  char format[] = "%hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_4) {
  char str[] = "123";
  char format[] = "%3hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_5) {
  char str[] = "+123";
  char format[] = "%3hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_6) {
  char str[] = "123";
  char format[] = "%3hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_7) {
  char str[] = "123";
  char format[] = "%4hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_8) {
  char str[] = "-123";
  char format[] = "%10hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}
END_TEST

START_TEST(sscanf_test_hd_9) {
  char str[] = "-123";
  char format[] = "%1hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}

START_TEST(sscanf_test_hd_10) {
  char str[] = "-5666987456";
  char format[] = "%hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}

START_TEST(sscanf_test_hd_11) {
  char str[] = "5666987456";
  char format[] = "%hd";
  short d11 = 0, d21 = 0;

  int original_result = sscanf(str, format, &d11);
  int my_result = s21_sscanf(str, format, &d21);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
}

START_TEST(sscanf_test_ld_1) {
  char str[] = "+123";
  char format[] = "%ld";
  long int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_ld_2) {
  char str[] = "-123";
  char format[] = "%ld";
  long int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_ld_3) {
  char str[] = "-123";
  char format[] = "%1ld";
  long int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_ld_4) {
  char str[] = "-123";
  char format[] = "%3ld";
  long int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_ld_5) {
  char str[] = "-123";
  char format[] = "%10ld";
  long int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_1) {
  char str[] = "123 222 -99";
  char format[] = "%i%i%i";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_i_2) {
  char str[] = "-123 -222 +99";
  char format[] = "%i %i %i";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_i_3) {
  char str[] = "0123";  // 83 в восьмиричном представление
  char format[] = "%i";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_4) {
  char str[] = "0x1A";  // 26 в шестандцатиричном представление
  char format[] = "%i";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_5) {
  char str[] = "123";
  char format[] = "%i";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_i_6) {
  char str[] = "0X123 +0x198 -0X87";
  char format[] = "%1i %1i %1i";
  unsigned int d11 = 0, d21 = 0;
  unsigned int q12 = 0, q22 = 0;
  unsigned int z13 = 0, z23 = 0;

  int original_result = sscanf(str, format, &d11, &q12, &z13);
  int my_result = s21_sscanf(str, format, &d21, &q22, &z23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d11, d21);
  ck_assert_uint_eq(q12, q22);
  ck_assert_uint_eq(z13, z23);
}
END_TEST

START_TEST(sscanf_test_i_7) {
  char str[] = "0X123 +0x198 -0X87";
  char format[] = "%3i %3i %3i";
  unsigned int d11 = 0, d21 = 0;
  unsigned int q12 = 0, q22 = 0;
  unsigned int z13 = 0, z23 = 0;

  int original_result = sscanf(str, format, &d11, &q12, &z13);
  int my_result = s21_sscanf(str, format, &d21, &q22, &z23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d11, d21);
  ck_assert_uint_eq(q12, q22);
  ck_assert_uint_eq(z13, z23);
}
END_TEST

START_TEST(sscanf_test_i_8) {
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  char format[] = "%3i %3i %3i %3i";
  unsigned int d11 = 0, d21 = 0;
  unsigned int q12 = 0, q22 = 0;
  unsigned int z13 = 0, z23 = 0;
  unsigned int w14 = 0, w24 = 0;

  int original_result = sscanf(str, format, &d11, &q12, &z13, &w14);
  int my_result = s21_sscanf(str, format, &d21, &q22, &z23, &w24);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d11, d21);
  ck_assert_uint_eq(q12, q22);
  ck_assert_uint_eq(z13, z23);
  ck_assert_uint_eq(w14, w24);
}
END_TEST

START_TEST(sscanf_test_hi_1) {
  char str[] = "-123 +198 99";
  char format[] = "%hi%hi%hi";
  unsigned short d11, d21;
  unsigned short z12, z22;
  unsigned short q13, q23;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_hi_2) {
  char str[] = "-12 +18 10";
  char format[] = "%hi %hi %hi";
  unsigned short d11, d21;
  unsigned short z12, z22;
  unsigned short q13, q23;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_hi_3) {
  char str[] = "-12 +18 10";
  char format[] = "%1hi %1hi %1hi";
  unsigned short d11 = 0, d21 = 0;
  unsigned short z12 = 0, z22 = 0;
  unsigned short q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_hi_4) {
  char str[] = "55 +100 -100";
  char format[] = "%3hi %3hi %3hi";
  unsigned short d11 = 0, d21 = 0;
  unsigned short z12 = 0, z22 = 0;
  unsigned short q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_hi_5) {
  char str[] = "55 +100 -100";
  char format[] = "%10hi %10hi %10hi";
  unsigned short d11 = 0, d21 = 0;
  unsigned short z12 = 0, z22 = 0;
  unsigned short q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_hi_6) {
  char str[] = "55 +100 -100";
  char format[] = "%30hi %23hi %15hi";
  unsigned short d11 = 0, d21 = 0;
  unsigned short z12 = 0, z22 = 0;
  unsigned short q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_hi_7) {
  char str[] = "-12 +18 10 1235 9987";
  char format[] = "%hi %hi %hi %hi %hi";
  unsigned short d11, d21;
  unsigned short z12, z22;
  unsigned short q13, q23;
  unsigned short s14, s24;
  unsigned short w15, w25;

  int original_result = sscanf(str, format, &d11, &z12, &q13, &s14, &w15);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23, &s24, &w25);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
  ck_assert_int_eq(s14, s24);
  ck_assert_int_eq(w15, w25);
}
END_TEST

START_TEST(sscanf_test_hi_8) {
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  char format[] = "%hi %hi %hi %hi %hi";
  unsigned short d11, d21;
  unsigned short z12, z22;
  unsigned short q13, q23;
  unsigned short s14, s24;
  unsigned short w15, w25;

  int original_result = sscanf(str, format, &d11, &z12, &q13, &s14, &w15);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23, &s24, &w25);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
  ck_assert_int_eq(s14, s24);
}
END_TEST

START_TEST(sscanf_test_li_1) {
  char str[] = "+123 222 -77";
  char format[] = "%li%li%li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_li_2) {
  char str[] = "+123 222 -77";
  char format[] = "%2li %2li %2li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_li_3) {
  char str[] = "+123 222 -77";
  char format[] = "%10li %20li %30li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_li_4) {
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  char format[] = "%li %li %li %li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;
  unsigned long int w14 = 0, w24 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13, &w14);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23, &w24);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
  ck_assert_int_eq(w14, w24);
}
END_TEST

START_TEST(sscanf_test_li_5) {
  char str[] = "013 +0137 -08";
  char format[] = "%3li %3li %3li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_li_6) {
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  char format[] = "%li %li %li %li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;
  unsigned long int w14 = 0, w24 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13, &w14);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23, &w24);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
  ck_assert_int_eq(w14, w24);
}
END_TEST

START_TEST(sscanf_test_li_7) {
  char str[] = "0x123 +0X198 -0x87";
  char format[] = "%3li %3li %3li";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_n_1) {
  char str[] = "David";
  char format[] = "%n";
  int n1 = 0, n2 = 0;

  int original_result = sscanf(str, format, &n2);
  int my_result = s21_sscanf(str, format, &n1);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_test_n_2) {
  char format[] = "%d %n %d %d %n";
  char str[] = "80 50 70 371 327";
  int d11 = 0, d12 = 0, d13 = 0;
  int d21 = 0, d22 = 0, d23 = 0;
  int n11 = 0, n12 = 0;
  int n21 = 0, n22 = 0;

  int res1 = s21_sscanf(str, format, &d11, &n11, &d12, &d13, &n12);
  int res2 = sscanf(str, format, &d21, &n21, &d22, &d23, &n22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(n11, n21);
  ck_assert_int_eq(d12, d22);
  ck_assert_int_eq(d13, d23);
  ck_assert_int_eq(n12, n22);
}
END_TEST

START_TEST(sscanf_test_n_3) {
  char format[] = "%s %n %d %n %s";
  char str[] = "David, 21 School";
  char s11[30], s12[30], s21[30], s22[30];
  int d1 = 0, d2 = 0;
  int n11 = 0, n12 = 0, n21 = 0, n22 = 0;

  int res1 = s21_sscanf(str, format, &s11, &n11, &d1, &n12, &s12);
  int res2 = sscanf(str, format, &s21, &n21, &d2, &n22, &s22);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s11, s21);
  ck_assert_int_eq(n11, n21);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n12, n22);
  ck_assert_pstr_eq(s12, s22);
}
END_TEST

START_TEST(sscanf_test_o_1) {
  char str[] = "123";
  char format[] = "%o";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_o_2) {
  char str[] = "123 -222";
  char format[] = "%o%o";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int original_result = sscanf(str, format, &d1, &z1);
  int my_result = s21_sscanf(str, format, &d2, &z2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_o_3) {
  char str[] = "123 -222 ";
  char format[] = "%o%o%o";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_o_4) {
  char str[] = "123 -222 -1723";
  char format[] = "%o %o %o";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

//тест на %ho
START_TEST(sscanf_test_ho_1) {
  char str[] = "123 +2 -1756";
  char format[] = "%ho %ho %ho";
  unsigned short d1 = 0, d2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_ho_2) {
  char str[] = "123 +2 -1756";
  char format[] = "%1ho %1ho %1ho";
  unsigned short d1 = 0, d2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_ho_3) {
  char str[] = "123 +2 -1756 +4";
  char format[] = "%ho %ho %ho %ho";
  unsigned short d1 = 0, d2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2, &w2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_ho_4) {
  char str[] = "123 +2 -1756";
  char format[] = "%10ho %22ho %44ho";
  unsigned short d1 = 0, d2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_ho_5) {
  char str[] = "123 +2 -1756";
  char format[] = "%3ho %3ho %3ho";
  unsigned short d1 = 0, d2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_test_ho_6) {
  char str[] = "123 +02 -1756 +04";
  char format[] = "%2ho %2ho %2ho %2ho";
  unsigned short d1 = 0, d2 = 0;
  unsigned short z1 = 0, z2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &q1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &q2, &w2);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lo_1) {
  char str[] = "+123 222 -77";
  char format[] = "%lo %lo %lo";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_lo_2) {
  char str[] = "+123 222 -77";
  char format[] = "%1lo %1lo %1lo";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_lo_3) {
  char str[] = "+123 222 -77";
  char format[] = "%3lo %3lo %3lo";
  unsigned long int d11 = 0, d21 = 0;
  unsigned long int z12 = 0, z22 = 0;
  unsigned long int q13 = 0, q23 = 0;

  int original_result = sscanf(str, format, &d11, &z12, &q13);
  int my_result = s21_sscanf(str, format, &d21, &z22, &q23);

  ck_assert_int_eq(original_result, my_result);
  ck_assert_int_eq(d11, d21);
  ck_assert_int_eq(z12, z22);
  ck_assert_int_eq(q13, q23);
}
END_TEST

START_TEST(sscanf_test_p_1) {
  char str[] = "0xAAAA";
  char format[] = "%p";
  int *p1 = 0, *p2 = 0;

  int original_result = sscanf(str, format, &p1);
  int my_result = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_ptr_eq(p2, p1);
}
END_TEST

START_TEST(sscanf_test_p_2) {
  char str[] = "0xAAAA";
  char format[] = "%3p";
  int *p1 = 0, *p2 = 0;

  int original_result = sscanf(str, format, &p1);
  int my_result = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_ptr_eq(p2, p1);
}
END_TEST

START_TEST(sscanf_test_p_3) {
  char str[] = "0xFFFFFF";
  char format[] = "%p";
  int *p1 = 0, *p2 = 0;

  int original_result = sscanf(str, format, &p1);
  int my_result = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_ptr_eq(p2, p1);
}
END_TEST

START_TEST(sscanf_test_p_4) {
  char str[] = "0x0000";
  char format[] = "%2p";
  int *p1 = 0, *p2 = 0;

  int original_result = sscanf(str, format, &p1);
  int my_result = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_ptr_eq(p2, p1);
}
END_TEST

START_TEST(sscanf_test_p_5) {
  char str[] = "1";
  char format[] = "%p";
  int *p1 = 0, *p2 = 0;

  int original_result = sscanf(str, format, &p1);
  int my_result = s21_sscanf(str, format, &p2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_ptr_eq(p2, p1);
}
END_TEST

START_TEST(sscanf_test_f_1) {
  char format[] = "%f";
  char str[] = "123";
  float d1, d2;

  int original_result = sscanf(str, format, &d2);
  int my_result = s21_sscanf(str, format, &d1);
  ck_assert_int_eq(my_result, original_result);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_f_2) {
  char format[] = "%f %f %f";
  char str[] = "123 -322 +77";
  float d1, d2;
  float z1, z2;
  float w1, w2;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(my_result, original_result);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_f_3) {
  char format[] = "%1f %1f %1f";
  char str[] = "123 -322 +77";
  float d1, d2;
  float z1, z2;
  float w1, w2;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(my_result, original_result);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_f_4) {
  char format[] = "%*f %7f %*f %*f";
  char str[] = "34.5 +6e3 83.2e-4 +43e+1 +2.43e3";
  float a1 = 0, a2 = 0;

  int res1 = s21_sscanf(str, format, &a1);
  int res2 = sscanf(str, format, &a2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_test_Lf_1) {
  char format[] = "%Lf %Lf %Lf %Lf";
  char str[] = "34.56e3 83.3e-4 .43e+1 +2.43e3";
  long double a1, a2;
  long double b1, b2;
  long double c1, c2;
  long double d1, d2;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_Lf_2) {
  char format[] = "%2Lf %2Lf %2Lf %2Lf";
  char str[] = "34 3. +45 +23E3 -0.3e4";
  long double a1 = 0, a2 = 0;
  long double b1 = 0, b2 = 0;
  long double c1 = 0, c2 = 0;
  long double d1 = 0, d2 = 0;

  int res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int res2 = sscanf(str, format, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_x_1) {
  char format[] = "%x";
  char str[] = "1a";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_x_2) {
  char format[] = "%x %x %x";
  char str[] = "1a 12a3 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_x_3) {
  char format[] = "%3x %3x %3x";
  char str[] = "1a 12a3 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_x_4) {
  char format[] = "%x %x %x";
  char str[] = "1a bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_x_5) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lx_1) {
  char format[] = "%lx%lx%lx";
  char str[] = "123 +99 -99";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lx_2) {
  char format[] = "%lx %lx %lx";
  char str[] = "123 +95 -963";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lx_3) {
  char format[] = "%lx %lx %lx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lx_4) {
  char format[] = "%lx %lx";
  char str[] = "0 +0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int original_result = sscanf(str, format, &d1, &z1);
  int my_result = s21_sscanf(str, format, &d2, &z2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lx_5) {
  char format[] = "%lx %lx %lx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lx_6) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lx_7) {
  char format[] = "%3lx %3lx %3lx";
  char str[] = "0x123 +0X4 -37x23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_X_1) {
  char format[] = "%X";
  char str[] = "1A";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_test_X_2) {
  char format[] = "%X %X %X";
  char str[] = "1A 12A3 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_X_3) {
  char format[] = "%3X %3X %3X";
  char str[] = "1A 12A3 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_X_4) {
  char format[] = "%X %X %X";
  char str[] = "1A BC 0X -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_X_5) {
  char format[] = "%1X %1X %1X";
  char str[] = "1A 0X -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int z1 = 0, z2 = 0;
  unsigned int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lX_1) {
  char format[] = "%lX%lX%lX";
  char str[] = "123 +99 -99";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lX_2) {
  char format[] = "%lX %lX %lX";
  char str[] = "123 +95 -963";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lX_3) {
  char format[] = "%lX %lX %lX";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lX_4) {
  char format[] = "%lX %lX";
  char str[] = "0 +0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int original_result = sscanf(str, format, &d1, &z1);
  int my_result = s21_sscanf(str, format, &d2, &z2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_test_lX_5) {
  char format[] = "%lX %lX %lX";
  char str[] = "0ABC4 -0XABC 0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lX_6) {
  char format[] = "%1lX %1lX %1lX";
  char str[] = "0ABC4 -0XABC 0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_lX_7) {
  char format[] = "%3lX %3lX %3lX";
  char str[] = "0X123 +0X4 -37X23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int z1 = 0, z2 = 0;
  unsigned long int w1 = 0, w2 = 0;

  int original_result = sscanf(str, format, &d1, &z1, &w1);
  int my_result = s21_sscanf(str, format, &d2, &z2, &w2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_test_u_1) {
  char format[] = "%u";
  char str[] = "12345";
  unsigned int d1 = 0, d2 = 0;

  int original_result = sscanf(str, format, &d1);
  int my_result = s21_sscanf(str, format, &d2);
  ck_assert_int_eq(original_result, my_result);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

// START_TEST(sscanf_test_u_2) {
//   char format[] = "%u%u";
//   char str[] = "12345 12345";
//   unsigned int d1 = 0, d2 = 0;
//   unsigned int z1 = 0, z2 = 0;
//
//   int original_result = sscanf(str, format, &d1, &z1);
//   int my_result = s21_sscanf(str, format, &d2, &z2);
//   ck_assert_int_eq(original_result, my_result);
//   ck_assert_uint_eq(d1, d2);
//   ck_assert_uint_eq(z1, z2);
// }
// END_TEST

Suite *sscanf_suite(void) {
  Suite *s = suite_create("s21_suite_sscanf");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_test_c_1);
  tcase_add_test(tc, sscanf_test_c_2);
  tcase_add_test(tc, sscanf_test_c_3);
  tcase_add_test(tc, sscanf_test_c_4);
  tcase_add_test(tc, sscanf_test_c_5);

  tcase_add_test(tc, sscanf_test_d_1);
  tcase_add_test(tc, sscanf_test_d_2);
  tcase_add_test(tc, sscanf_test_d_3);
  tcase_add_test(tc, sscanf_test_d_4);
  tcase_add_test(tc, sscanf_test_d_5);
  tcase_add_test(tc, sscanf_test_d_6);
  tcase_add_test(tc, sscanf_test_d_7);
  tcase_add_test(tc, sscanf_test_d_8);
  tcase_add_test(tc, sscanf_test_d_9);

  tcase_add_test(tc, sscanf_test_hd_1);
  tcase_add_test(tc, sscanf_test_hd_2);
  tcase_add_test(tc, sscanf_test_hd_3);
  tcase_add_test(tc, sscanf_test_hd_4);
  tcase_add_test(tc, sscanf_test_hd_5);
  tcase_add_test(tc, sscanf_test_hd_6);
  tcase_add_test(tc, sscanf_test_hd_7);
  tcase_add_test(tc, sscanf_test_hd_8);
  tcase_add_test(tc, sscanf_test_hd_9);
  tcase_add_test(tc, sscanf_test_hd_10);
  tcase_add_test(tc, sscanf_test_hd_11);

  tcase_add_test(tc, sscanf_test_ld_1);
  tcase_add_test(tc, sscanf_test_ld_2);
  tcase_add_test(tc, sscanf_test_ld_3);
  tcase_add_test(tc, sscanf_test_ld_4);
  tcase_add_test(tc, sscanf_test_ld_5);

  tcase_add_test(tc, sscanf_test_i_1);
  tcase_add_test(tc, sscanf_test_i_2);
  tcase_add_test(tc, sscanf_test_i_3);
  tcase_add_test(tc, sscanf_test_i_4);
  tcase_add_test(tc, sscanf_test_i_5);
  tcase_add_test(tc, sscanf_test_i_6);
  tcase_add_test(tc, sscanf_test_i_7);
  tcase_add_test(tc, sscanf_test_i_8);

  tcase_add_test(tc, sscanf_test_hi_1);
  tcase_add_test(tc, sscanf_test_hi_2);
  tcase_add_test(tc, sscanf_test_hi_3);
  tcase_add_test(tc, sscanf_test_hi_4);
  tcase_add_test(tc, sscanf_test_hi_5);
  tcase_add_test(tc, sscanf_test_hi_6);
  tcase_add_test(tc, sscanf_test_hi_7);
  tcase_add_test(tc, sscanf_test_hi_8);

  tcase_add_test(tc, sscanf_test_li_1);
  tcase_add_test(tc, sscanf_test_li_2);
  tcase_add_test(tc, sscanf_test_li_3);
  tcase_add_test(tc, sscanf_test_li_4);
  tcase_add_test(tc, sscanf_test_li_5);
  tcase_add_test(tc, sscanf_test_li_6);
  tcase_add_test(tc, sscanf_test_li_7);

  tcase_add_test(tc, sscanf_test_n_1);
  tcase_add_test(tc, sscanf_test_n_2);
  tcase_add_test(tc, sscanf_test_n_3);

  tcase_add_test(tc, sscanf_test_o_1);
  tcase_add_test(tc, sscanf_test_o_2);
  tcase_add_test(tc, sscanf_test_o_3);
  tcase_add_test(tc, sscanf_test_o_4);

  tcase_add_test(tc, sscanf_test_ho_1);
  tcase_add_test(tc, sscanf_test_ho_2);
  tcase_add_test(tc, sscanf_test_ho_3);
  tcase_add_test(tc, sscanf_test_ho_4);
  tcase_add_test(tc, sscanf_test_ho_5);
  tcase_add_test(tc, sscanf_test_ho_6);

  tcase_add_test(tc, sscanf_test_lo_1);
  tcase_add_test(tc, sscanf_test_lo_2);
  tcase_add_test(tc, sscanf_test_lo_3);

  tcase_add_test(tc, sscanf_test_p_1);
  tcase_add_test(tc, sscanf_test_p_2);
  tcase_add_test(tc, sscanf_test_p_3);
  tcase_add_test(tc, sscanf_test_p_4);
  tcase_add_test(tc, sscanf_test_p_5);

  tcase_add_test(tc, sscanf_test_f_1);
  tcase_add_test(tc, sscanf_test_f_2);
  tcase_add_test(tc, sscanf_test_f_3);
  tcase_add_test(tc, sscanf_test_f_4);

  tcase_add_test(tc, sscanf_test_Lf_1);
  tcase_add_test(tc, sscanf_test_Lf_2);

  tcase_add_test(tc, sscanf_test_x_1);
  tcase_add_test(tc, sscanf_test_x_2);
  tcase_add_test(tc, sscanf_test_x_3);
  tcase_add_test(tc, sscanf_test_x_4);
  tcase_add_test(tc, sscanf_test_x_5);

  tcase_add_test(tc, sscanf_test_lx_1);
  tcase_add_test(tc, sscanf_test_lx_2);
  tcase_add_test(tc, sscanf_test_lx_3);
  tcase_add_test(tc, sscanf_test_lx_4);
  tcase_add_test(tc, sscanf_test_lx_5);
  tcase_add_test(tc, sscanf_test_lx_6);
  tcase_add_test(tc, sscanf_test_lx_7);

  tcase_add_test(tc, sscanf_test_X_1);
  tcase_add_test(tc, sscanf_test_X_2);
  tcase_add_test(tc, sscanf_test_X_3);
  tcase_add_test(tc, sscanf_test_X_4);
  tcase_add_test(tc, sscanf_test_X_5);

  tcase_add_test(tc, sscanf_test_lX_1);
  tcase_add_test(tc, sscanf_test_lX_2);
  tcase_add_test(tc, sscanf_test_lX_3);
  tcase_add_test(tc, sscanf_test_lX_4);
  tcase_add_test(tc, sscanf_test_lX_5);
  tcase_add_test(tc, sscanf_test_lX_6);
  tcase_add_test(tc, sscanf_test_lX_7);

  tcase_add_test(tc, sscanf_test_u_1);
  //  tcase_add_test(tc, sscanf_test_u_2);

  suite_add_tcase(s, tc);
  return s;
}
