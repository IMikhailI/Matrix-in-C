#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;

  if (s21_is_matrix_valid_full(A) == 1 || s21_is_matrix_valid_full(B) == 1) {
    return_code = INCORRECT_MATRIX;
    return return_code;
  }
  if (!s21_eq_sizes_matrix(A, B)) {
    return_code = ERROR_CALCULATION;
    return return_code;
  }
  double temp = 0.0;
  return_code = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows && return_code == OK; i++) {
    for (int j = 0; j < A->columns && return_code == OK; j++) {
      temp = A->matrix[i][j] - B->matrix[i][j];
      if (isfinite(temp) != 0) {
        result->matrix[i][j] = temp;
      } else {
        return_code = ERROR_CALCULATION;
      }
    }
  }

  return return_code;
}