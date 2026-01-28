#include "s21_matrix_test.h"

int main() {
  Suite *suites[] = {s21_create_matrix_suite(),
                     s21_remove_matrix_suite(),
                     s21_eq_matrix_suite(),
                     s21_sum_matrix_suite(),
                     s21_sub_matrix_suite(),
                     s21_mult_number_suite(),
                     s21_mult_matrix_suite(),
                     s21_transpose_matrix_suite(),
                     s21_calc_complements_matrix_suite(),
                     s21_determinant_matrix_suite(),
                     s21_inverse_matrix_suite(),
                     NULL};

  for (int i = 0; suites[i]; i++) {
    fprintf(
        stderr,
        "------------------------------------------------------------------"
        "--------------------------------------------------------------\n\n");
    SRunner *runner = srunner_create(suites[i]);
    srunner_run_all(runner, CK_NORMAL);
    srunner_free(runner);
    fprintf(
        stderr,
        "------------------------------------------------------------------"
        "--------------------------------------------------------------\n\n");
  }

  return 0;
}

// void s21_initialize_matrix(matrix_t *A, double start_value,
//                            double iteration_step) {
//   if (A != NULL && A->matrix != NULL) {
//     double value = start_value;
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; j < A->columns; j++) {
//         A->matrix[i][j] = value;
//         value += iteration_step;
//       }
//     }
//   }
// }

// void s21_init_matrix(double number, matrix_t *A) {
//   for (int x = 0; x < A->rows; x += 1) {
//     for (int y = 0; y < A->columns; number += 1.0, y += 1)
//       A->matrix[x][y] = number;
//   }
// }

void fill_matrix(matrix_t *A, const double numbers[]) {
  int k = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, k++) {
      A->matrix[i][j] = numbers[k];
    }
  }
}