#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code = OK;

  if (result == NULL || s21_is_matrix_valid_full(A))
    return_code = INCORRECT_MATRIX;
  else if (A->rows != A->columns)
    return_code = ERROR_CALCULATION;
  else if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1.0;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    matrix_t M;
    s21_create_matrix(A->rows - 1, A->columns - 1, &M);

    double det_minor = 0.0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_minor(i, j, A, &M);
        s21_determinant(&M, &det_minor);
        result->matrix[i][j] = det_minor * pow(-1.0, i + j);
      }
    }
    s21_remove_matrix(&M);
  }

  return return_code;
}