#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_code = OK;

  if (s21_is_matrix_valid_full(A) == 1 || number == INFINITY ||
      result == NULL) {
    return_code = INCORRECT_MATRIX;
    return return_code;
  }
  double temp = 0.0;
  return_code = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && return_code == OK; i++) {
    for (int j = 0; j < A->columns && return_code == OK; j++) {
      temp = A->matrix[i][j] * number;
      if (isfinite(temp) != 0) {
        result->matrix[i][j] = temp;
      } else {
        return_code = ERROR_CALCULATION;
      }
    }
  }

  return return_code;
}