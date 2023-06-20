#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(abs_test) {
  ck_assert_int_eq(abs(-21), s21_abs(-21));
  ck_assert_int_eq(abs(21), s21_abs(21));
  ck_assert_int_eq(abs(-5000), s21_abs(-5000));
  ck_assert_int_eq(abs(0), s21_abs(0));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq(fabs(2.1), s21_fabs(2.1));
  ck_assert_double_eq(fabs(-2.1), s21_fabs(-2.1));
  ck_assert_double_eq(fabs(0.21), s21_fabs(0.21));
  ck_assert_double_eq(fabs(0.0), s21_fabs(0.0));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq(floor(0), s21_floor(0));
  ck_assert_double_eq(floor(-2.1), s21_floor(-2.1));
  ck_assert_double_eq(floor(-5532.2), s21_floor(-5532.2));
  ck_assert_double_eq(floor(21.21), s21_floor(21.21));
  ck_assert_double_eq(floor(1250.60), s21_floor(1250.60));
  ck_assert_double_infinite(s21_floor(S21_INF_POS));
}

START_TEST(ceil_test) {
  ck_assert_double_eq(ceil(0), s21_ceil(0));
  ck_assert_double_eq(ceil(-2.1), s21_ceil(-2.1));
  ck_assert_double_eq(ceil(-5532.2), s21_ceil(-5532.2));
  ck_assert_double_eq(ceil(21.21), s21_ceil(21.21));
  ck_assert_double_eq(ceil(1250.60), s21_ceil(1250.60));
  ck_assert_double_infinite(s21_ceil(S21_INF_NEG));
}

START_TEST(fmod_test) {
  ck_assert_double_eq(fmod(2355.6, 4.5), s21_fmod(2355.6, 4.5));
  ck_assert_double_eq(fmod(1.2, 45), s21_fmod(1.2, 45));
  ck_assert_double_eq(fmod(2256.3, -2), s21_fmod(2256.3, -2));
  ck_assert_double_nan(s21_fmod(S21_INF_NEG, -2));
}
END_TEST

START_TEST(pow_test) {
  ck_assert_double_eq_tol(pow(2544, 0.3), s21_pow(2544, 0.3), 0.000001);
  ck_assert_double_eq_tol(pow(44, 0), s21_pow(44, 0), 0.000001);
  ck_assert_double_eq_tol(pow(1, 20), s21_pow(1, 20), 0.000001);
  ck_assert_double_eq(pow(S21_INF_NEG, 0.3), s21_pow(S21_INF_NEG, 0.3));
  ck_assert_double_eq(pow(S21_INF_NEG, -1), s21_pow(S21_INF_NEG, -1));
  ck_assert_double_eq(pow(-1, S21_INF_NEG), s21_pow(-1, S21_INF_NEG));
  ck_assert_double_eq(pow(0.3, S21_INF_NEG), s21_pow(0.3, S21_INF_NEG));
  ck_assert_double_eq(pow(3, S21_INF_NEG), s21_pow(3, S21_INF_NEG));
  ck_assert_double_nan(s21_pow(S21_NAN, 2));
}
END_TEST

START_TEST(sqrt_test) {
  ck_assert_double_eq_tol(sqrt(0), s21_sqrt(0), 0.000001);
  ck_assert_double_eq_tol(sqrt(4.2), s21_sqrt(4.2), 0.000001);
  ck_assert_double_eq_tol(sqrt(2553), s21_sqrt(2553), 0.000001);
  ck_assert_double_nan(s21_sqrt(-0.5));
}
END_TEST

START_TEST(exp_test) {
  ck_assert_double_eq_tol(exp(-2), s21_exp(-2), 0.000001);
  ck_assert_double_eq_tol(exp(0), s21_exp(0), 0.000001);
  ck_assert_double_eq_tol(exp(12), s21_exp(12), 0.000001);
  ck_assert_double_eq_tol(exp(125.6), s21_exp(125.6), 0.000001);
  ck_assert_double_infinite(s21_exp(S21_INF_POS));
}
END_TEST

START_TEST(log_test) {
  ck_assert_double_eq_tol(log(20), s21_log(20), 0.000001);
  ck_assert_double_eq_tol(log(2.3), s21_log(2.3), 0.000001);
  ck_assert_double_nan(s21_log(-20));
  ck_assert_double_infinite(s21_log(0));
  ck_assert_double_infinite(s21_log(S21_INF_POS));
}
END_TEST

START_TEST(sin_test) {
  ck_assert_double_eq_tol(sin(-S21_PI), s21_sin(-S21_PI), 0.000001);
  ck_assert_double_eq_tol(sin(S21_PI), s21_sin(S21_PI), 0.000001);
  ck_assert_double_eq_tol(sin(2 * S21_PI), s21_sin(2 * S21_PI), 0.000001);
  ck_assert_double_eq_tol(sin(-2 * S21_PI), s21_sin(-2 * S21_PI), 0.000001);
  ck_assert_double_eq_tol(sin(0), s21_sin(0), 0.000001);
  ck_assert_double_eq_tol(sin(5000), s21_sin(5000), 0.000001);
  ck_assert_double_nan(sin(S21_INF_POS));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_double_eq_tol(cos(40 * S21_PI), s21_cos(40 * S21_PI), 0.000001);
  ck_assert_double_eq_tol(cos(S21_PI), s21_cos(S21_PI), 0.000001);
  ck_assert_double_eq_tol(cos(S21_PI / 2), s21_cos(S21_PI / 2), 0.000001);
  ck_assert_double_eq_tol(cos(-2 * S21_PI), s21_cos(-2 * S21_PI), 0.000001);
  ck_assert_double_eq_tol(cos(0), s21_cos(0), 0.000001);
  ck_assert_double_nan(cos(S21_INF_NEG));
}
END_TEST

START_TEST(tan_test) {
  ck_assert_double_eq_tol(tan(1.01), s21_tan(1.01), 0.000001);
  ck_assert_double_eq_tol(tan(-21.4), s21_tan(-21.4), 0.000001);
  ck_assert_double_eq_tol(tan(22.256), s21_tan(22.256), 0.000001);
  ck_assert_double_eq_tol(tan(0), s21_tan(0), 0.000001);
}
END_TEST

START_TEST(atan_test) {
  ck_assert_double_eq_tol(atan(0.9), s21_atan(0.9), 0.000001);
  ck_assert_double_eq_tol(atan(-0.22), s21_atan(-0.22), 0.000001);
  ck_assert_double_eq_tol(atan(0), s21_atan(0), 0.000001);
  ck_assert_double_eq_tol(atan(24.22), s21_atan(24.22), 0.000001);
  ck_assert_double_eq_tol(atan(S21_INF_POS), s21_atan(S21_INF_POS), 0.000001);
  ck_assert_double_eq_tol(atan(1), s21_atan(1), 0.000001);
}
END_TEST

START_TEST(asin_test) {
  ck_assert_double_eq_tol(asin(0.24), s21_asin(0.24), 0.000001);
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 0.000001);
  ck_assert_double_eq_tol(asin(-0.99), s21_asin(-0.99), 0.000001);
  ck_assert_double_eq_tol(asin(0), s21_asin(0), 0.000001);
  ck_assert_double_nan(s21_asin(1.01));
  ck_assert_double_nan(s21_asin(-1.01));
}
END_TEST

START_TEST(acos_test) {
  ck_assert_double_eq_tol(acos(0.111), s21_acos(0.111), 0.000001);
  ck_assert_double_eq_tol(acos(0.999), s21_acos(0.999), 0.000001);
  ck_assert_double_eq_tol(acos(0), s21_acos(0), 0.000001);
  ck_assert_double_nan(s21_acos(-1.01));
  ck_assert_double_nan(s21_acos(1.01));
}
END_TEST

Suite *s21_math_create_tests(void) {
  Suite *suite = suite_create("S21_MATH");
  TCase *tcase_core = tcase_create("S21_MATH_TESTS");
  tcase_add_test(tcase_core, abs_test);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, fmod_test);
  tcase_add_test(tcase_core, pow_test);
  tcase_add_test(tcase_core, sqrt_test);
  tcase_add_test(tcase_core, exp_test);
  tcase_add_test(tcase_core, log_test);
  tcase_add_test(tcase_core, sin_test);
  tcase_add_test(tcase_core, cos_test);
  tcase_add_test(tcase_core, tan_test);
  tcase_add_test(tcase_core, atan_test);
  tcase_add_test(tcase_core, asin_test);
  tcase_add_test(tcase_core, acos_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = s21_math_create_tests();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);
  return 0;
}