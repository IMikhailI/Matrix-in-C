#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_code = OK;

  if (result == NULL || s21_is_matrix_valid_full(A))
    return INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    return ERROR_CALCULATION;

  double det = 0.0;
  s21_determinant(A, &det);

  if (det != 0.0) {
    matrix_t M;
    matrix_t T;
    s21_calc_complements(A, &M);
    s21_transpose(&M, &T);
    s21_mult_number(&T, 1.0 / det, result);
    s21_remove_matrix(&M);
    s21_remove_matrix(&T);
  } else {
    return_code = ERROR_CALCULATION;
  }

  return return_code;
}