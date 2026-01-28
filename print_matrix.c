#include <stdio.h>

#include "s21_matrix.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

void print_matrix(const matrix_t* mat) {
  // Print column numbers
  printf("     ");
  for (int j = 0; j < mat->columns; j++) {
    printf(ANSI_COLOR_GREEN "    [%2d]    ", j + 1);
  }
  printf("\n");

  printf(ANSI_COLOR_CYAN "    ╔");
  for (int j = 0; j < mat->columns; j++) {
    printf("════════════");
    if (j < mat->columns - 1) printf("╦");
  }
  printf("╗\n");

  for (int i = 0; i < mat->rows; ++i) {
    printf(ANSI_COLOR_GREEN "[%2d]", i + 1);
    printf(ANSI_COLOR_CYAN "║");
    for (int j = 0; j < mat->columns; ++j) {
      printf(ANSI_COLOR_YELLOW " % 8f ", mat->matrix[i][j]);
      if (j < mat->columns - 1) printf(ANSI_COLOR_CYAN "║");
    }
    printf(ANSI_COLOR_CYAN "║\n");

    if (i < mat->rows - 1) {
      printf(ANSI_COLOR_CYAN "    ╠");
      for (int j = 0; j < mat->columns; j++) {
        printf("════════════");
        if (j < mat->columns - 1) printf("╬");
      }
      printf("╣\n");
    }
  }

  printf(ANSI_COLOR_CYAN "    ╚");
  for (int j = 0; j < mat->columns; j++) {
    printf("════════════");
    if (j < mat->columns - 1) printf("╩");
  }
  printf("╝\n" ANSI_COLOR_RESET);
}