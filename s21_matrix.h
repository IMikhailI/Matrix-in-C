#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

// matrix_t - структура, которая хранит матрицу и её размеры
typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

// return codes
enum { OK, INCORRECT_MATRIX, ERROR_CALCULATION };

// main functions
void print_matrix(const matrix_t* mat);
int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

// assistant functions
int s21_is_matrix_valid(const matrix_t* matrix);
int s21_is_matrix_valid_full(const matrix_t* matrix);
int s21_eq_sizes_matrix(const matrix_t* A, const matrix_t* B);
int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
void s21_initialize_matrix(matrix_t* A, double start_value,
                           double iteration_step);
void s21_init_matrix(double number, matrix_t* A);
void s21_minor(int row, int col, matrix_t* A, matrix_t* result);
void s21_copy_matrix(matrix_t* A, matrix_t* result);

#endif

// Все операции (кроме сравнения матриц) должны возвращать результирующий код:

// 0 — OK;
// 1 — Ошибка некорректная матрица;
// 2 — Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т. д.).
