#ifndef S21_TEST_H
#define S21_TEST_H

#include <check.h>
// #include <float.h>

#include "../s21_matrix.h"
// #include "../s21_matrix/s21_other_func.h"

#define ERROR_INIT 1
#define ERROR_CALC 2

Suite *s21_create_matrix_suite(void);
Suite *s21_remove_matrix_suite(void);
Suite *s21_eq_matrix_suite(void);
Suite *s21_sum_matrix_suite(void);
Suite *s21_sub_matrix_suite(void);
Suite *s21_mult_number_suite(void);
Suite *s21_mult_matrix_suite(void);
Suite *s21_transpose_matrix_suite(void);
Suite *s21_calc_complements_matrix_suite(void);
Suite *s21_determinant_matrix_suite(void);
Suite *s21_inverse_matrix_suite(void);

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step);
// void s21_init_matrix(double number, matrix_t *A);
void fill_matrix(matrix_t *A, const double numbers[]);

#endif