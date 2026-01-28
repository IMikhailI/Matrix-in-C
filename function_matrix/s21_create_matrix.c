#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_code = OK;

  if (rows < 1 || columns < 1 || result == NULL) {
    return_code = INCORRECT_MATRIX;
    return return_code;
  }

  result->columns = columns;
  result->rows = rows;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  // if (result->matrix == NULL) {
  //   return_code = INCORRECT_MATRIX;
  // }

  int i = 0;
  for (; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    // if (result->matrix[i] == NULL) {
    //   stop = 0;
    // }
  }

  // if (i < rows) {
  //   while (--i >= 0) {
  //     free(result->matrix[i]);
  //   }
  //   free(result->matrix);
  //   return_code = INCORRECT_MATRIX;
  // }

  return return_code;
}
