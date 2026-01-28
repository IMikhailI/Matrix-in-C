#include "s21_matrix_test.h"

START_TEST(create_1) {
  const int rows = 1;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_2) {
  const int rows = 10;
  const int cols = 1;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_3) {
  const int rows = -1;
  const int cols = -1;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_4) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_5) {
  const int rows = 0;
  const int cols = 10;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INCORRECT_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_6) {
  const int rows = 50;
  const int cols = 50;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_7) {
  const int rows = 0;
  const int cols = 10;

  ck_assert_int_eq(s21_create_matrix(rows, cols, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_8) {
  const int rows = 10;
  const int cols = 0;

  ck_assert_int_eq(s21_create_matrix(rows, cols, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_9) {
  const int rows = 10;
  const int cols = 10;

  ck_assert_int_eq(s21_create_matrix(rows, cols, NULL), INCORRECT_MATRIX);
}
END_TEST

Suite *s21_create_matrix_suite(void) {
  Suite *s = suite_create("s21_create_matrix_suite");
  TCase *tc = tcase_create("s21_create_matrix_suite");
  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, create_4);
  tcase_add_test(tc, create_5);
  tcase_add_test(tc, create_6);
  tcase_add_test(tc, create_7);
  tcase_add_test(tc, create_8);
  tcase_add_test(tc, create_9);
  suite_add_tcase(s, tc);
  return s;
}