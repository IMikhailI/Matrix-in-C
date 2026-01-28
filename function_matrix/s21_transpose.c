#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_code = OK;

  if (s21_is_matrix_valid_full(A) == 1 || result == NULL) {
    return_code = INCORRECT_MATRIX;
    return return_code;
  }

  return_code = s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->columns && return_code == OK; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return return_code;
}

// int s21_transpose(matrix_t *A, matrix_t *result) {
//   int return_code = OK;

//   if (s21_check_matrix(A) || result == NULL)
//     return_code = INCORRECT_MATRIX;
//   else {
//     s21_create_matrix(A->columns, A->rows, result);
//     for (int i = 0; i < A->rows; i++)
//       for (int j = 0; j < A->columns; j++) {
//         result->matrix[j][i] = A->matrix[i][j];
//       }
//   }

//   return return_code;
// }