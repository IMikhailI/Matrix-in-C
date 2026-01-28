#include "../s21_matrix.h"

int s21_is_matrix_valid(const matrix_t *matrix) {
  return matrix != NULL && matrix->matrix != NULL && matrix->rows > 0 &&
         matrix->columns > 0;
}

int s21_is_matrix_valid_full(const matrix_t *matrix) {
  int return_code = OK;

  if (s21_is_matrix_valid(matrix) == 0) {
    return_code = INCORRECT_MATRIX;
    return return_code;
  }

  for (int i = 0; i < matrix->rows && return_code == OK; i++) {
    if (matrix->matrix[i] != NULL)
      return_code = OK;
    else {
      return_code = INCORRECT_MATRIX;
    }
  }

  // А НАДО ЛИ???
  for (int i = 0; i < matrix->rows && return_code == OK; i++) {
    for (int j = 0; j < matrix->columns && return_code == OK; j++) {
      if (isfinite(matrix->matrix[i][j]))
        return_code = OK;
      else {
        return_code = INCORRECT_MATRIX;
      }
    }
  }

  return return_code;
}

int s21_eq_sizes_matrix(const matrix_t *A, const matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

void s21_initialize_matrix(matrix_t *A, double start_value,
                           double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

void s21_minor(int row, int col, matrix_t *A, matrix_t *result) {
  int n, m = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    n = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) continue;
      result->matrix[m][n] = A->matrix[i][j];
      n++;
    }
    m++;
  }
}

void s21_copy_matrix(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j];
    }
  }
}