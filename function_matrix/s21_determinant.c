#include "../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (s21_is_matrix_valid_full(A) || result == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return ERROR_CALCULATION;
  int count_row = A->rows;
  int flag = 0;
  double det = 1.0;
  matrix_t tmp = {0};
  s21_create_matrix(count_row, count_row, &tmp);
  s21_copy_matrix(A, &tmp);
  // Приведение к верхнетреугольному виду
  for (int i = 0; i < count_row && flag == 0; i++) {
    int max_row = i;
    for (int k = i + 1; k < count_row; k++) {
      if (fabs(tmp.matrix[k][i]) > fabs(tmp.matrix[max_row][i])) {
        max_row = k;
      }
    }
    if (max_row != i) {
      for (int j = i; j < count_row; j++) {
        double temp = tmp.matrix[i][j];
        tmp.matrix[i][j] = tmp.matrix[max_row][j];
        tmp.matrix[max_row][j] = temp;
      }
      det *= -1;
    }
    if (fabs(tmp.matrix[i][i]) < 1e-7) {
      *result = 0;
      flag = 1;
    }
    for (int k = i + 1; k < count_row && flag == 0; k++) {
      double factor = tmp.matrix[k][i] / tmp.matrix[i][i];
      for (int j = i; j < count_row; j++) {
        tmp.matrix[k][j] -= factor * tmp.matrix[i][j];
      }
    }
  }
  if (flag == 0) {
    for (int i = 0; i < count_row; i++) {
      det *= tmp.matrix[i][i];
    }
    *result = det;
  }
  s21_remove_matrix(&tmp);
  return OK;
}