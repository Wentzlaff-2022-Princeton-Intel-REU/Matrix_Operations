/*--------------------------------------------------------------------*/
/* main.c                                                             */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "add.h"
#include "multiply.h"
#include "print.h"
#include "reading.h"

/*--------------------------------------------------------------------*/

int main(int argc, char *argv[]) {

    if(argc != 6) {
        fprintf(stderr, "Usage: %s 5 values needed\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int m_A = atoi(argv[1]);
    int n_A = atoi(argv[2]);
    int m_B = atoi(argv[3]);
    int n_B = atoi(argv[4]);
    int isAdd = atoi(argv[5]);

    Matrix_t matrix_A, matrix_B;
    readMatrices(&matrix_A, &matrix_B, m_A, m_B, n_A, n_B);
    Matrix_t result;

    struct timespec tp1;
    clock_gettime(CLOCK_MONOTONIC, &tp1);

    if (isAdd == 1) {
        result = add(matrix_A, matrix_B);
        printf("\nA + B = \n");
    }
    else if (isAdd == 0) {
        result = multiply(matrix_A, matrix_B);
        printf("\nA • B = \n");
    }
    printMatrix(result);

    struct timespec tp2;
    int time2 = clock_gettime(CLOCK_MONOTONIC, &tp2);
    printf("\nRuntime: %ld nanoseconds\n", (tp2.tv_nsec - tp1.tv_nsec));

    // free matrices
    free_mat(&matrix_A);
    free_mat(&matrix_B);
    free_mat(&result);

    return 0;
}