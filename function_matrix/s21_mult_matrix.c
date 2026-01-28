#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;

  if (s21_is_matrix_valid_full(A) != OK || s21_is_matrix_valid_full(B) != OK ||
      result == NULL) {
    return_code = INCORRECT_MATRIX;
    return return_code;
  } else if (A->columns != B->rows) {
    return_code = ERROR_CALCULATION;
    return return_code;
  }

  return_code = s21_create_matrix(A->rows, B->columns, result);
  if (return_code == OK) {
    return_code = mult_matrix(A, B, result);
  }

  return return_code;
}

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;

  for (int i = 0; i < A->rows && return_code == OK; i++) {
    for (int j = 0; j < B->columns && return_code == OK; j++) {
      double temp = 0.0;
      for (int k = 0; k < A->columns && return_code == OK; k++) {
        double product = A->matrix[i][k] * B->matrix[k][j];
        if (isfinite(product)) {
          temp += product;
        } else {
          return_code = ERROR_CALCULATION;
          break;
        }
      }
      if (return_code == OK) {
        if (isfinite(temp)) {
          result->matrix[i][j] = temp;
        } else {
          return_code = ERROR_CALCULATION;
        }
      }
    }
  }

  return return_code;
}
