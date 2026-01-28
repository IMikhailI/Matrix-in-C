#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_code = SUCCESS;

  if (!s21_is_matrix_valid(A) || !s21_is_matrix_valid(B) ||
      !s21_eq_sizes_matrix(A, B)) {
    return_code = FAILURE;
    return return_code;
  }

  int stop = 1;
  for (int i = 0; i < A->rows && stop == 1; i++) {
    for (int j = 0; j < A->columns && stop == 1; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        return_code = FAILURE;
        stop = 0;
      }
    }
  }

  return return_code;
}