#include "s21_matrix.h"

int main() {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  int res = s21_mult_matrix(&A, &B, &result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  if (res == ERROR_CALCULATION) {
    printf("ERROR_CALCULATION\n");
  } else if (res == INCORRECT_MATRIX) {
    printf("INCORRECT_MATRIX\n");
  } else if (res == OK) {
    printf("OK\n");
  }

  //   int return_code = OK;
  //   const int rows = 3;
  //   const int cols = 3;
  //   matrix_t m = {0};
  //   return_code = s21_create_matrix(rows, cols, &m);

  //   const int rows = 3;
  //   const int cols = 3;
  //   matrix_t a = {0};
  //   matrix_t b = {0};
  //   return_code = s21_eq_matrix(&a, &b);
  //   if (return_code == OK) {
  //     m.matrix[0][0] = 1.0;
  //     m.matrix[0][1] = 4.122123132;
  //     m.matrix[1][0] = 2.0;
  //     m.matrix[1][1] = 5.0;
  //     m.matrix[2][0] = 3.0;
  //     m.matrix[2][1] = 6.1212123;
  //     print_matrix(&m);
  //   } else if (return_code == INCORRECT_MATRIX) {
  //     printf("Error data\n");
  //   } else if (return_code == ERROR_CALCULATION) {
  //     printf("Error calculation\n");
  //   }
  //   s21_remove_matrix(&m);
  return 0;
}