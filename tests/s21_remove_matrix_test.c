#include "s21_matrix_test.h"

START_TEST(s21_remove_matrix_1) {
  // success remove
  matrix_t A = {};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST
START_TEST(s21_remove_matrix_01) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(2, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST
START_TEST(s21_remove_matrix_2) {
  // failure null
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST
START_TEST(s21_remove_matrix_02) {
  int res = 0;
  matrix_t A;

  res = s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 3.14;
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST
START_TEST(s21_remove_matrix_3) {
  // failure
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST
START_TEST(s21_remove_matrix_03) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST
START_TEST(s21_remove_matrix_04) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 4, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST
START_TEST(s21_remove_matrix_05) {
  int res = 0;
  matrix_t A = {0};

  res = s21_create_matrix(3, 2, &A);
  s21_remove_matrix(&A);
  if (A.matrix != NULL) {
    res = 1;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST
START_TEST(s21_remove_null_pointer) {
  // INCORRECT_MATRIX
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_null_pointer_matrix) {
  // A.matrix = NULL
  matrix_t A;
  A.matrix = NULL;
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

Suite *s21_remove_matrix_suite(void) {
  Suite *s = suite_create("s21_remove_matrix_suite");
  TCase *tc = tcase_create("s21_remove_matrix_suite");

  tcase_add_test(tc, s21_remove_matrix_1);
  tcase_add_test(tc, s21_remove_matrix_01);
  tcase_add_test(tc, s21_remove_matrix_2);
  tcase_add_test(tc, s21_remove_matrix_02);
  tcase_add_test(tc, s21_remove_matrix_3);
  tcase_add_test(tc, s21_remove_matrix_03);
  tcase_add_test(tc, s21_remove_matrix_04);
  tcase_add_test(tc, s21_remove_matrix_05);
  tcase_add_test(tc, s21_remove_null_pointer);
  tcase_add_test(tc, s21_remove_null_pointer_matrix);
  tcase_add_test(tc, s21_remove_normal);
  suite_add_tcase(s, tc);
  return s;
}