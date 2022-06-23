/*------------------------------------------------------------*/
/* reading.c                                                  */
/* Author: Dara Oseyemi                                       */
/*------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "reading.h"

/*------------------------------------------------------------*/
static void setArray(double* arr, int row, int col) {
    for (int i = 0; i < row; i++) {
            char temp;
        for (int j = 0; j < col; j++) {
            scanf("%lf%c", &arr[i*column + j], &temp);
            if (temp != ' ') {
                exit(2);
            }
        }
        if (temp != '\n') {
            exit(2);
        }
    }
}

void readMatrices(Matrix_t* matrix_A, Matrix_t* matrix_B, int m_A, int m_B, int n_A, int n_B) {
    double* a = (double*)malloc(sizeof(double) * m_A * n_A);
    double* b = (double*)malloc(sizeof(double) * m_B * n_B);
    if (a == NULL || b == NULL) {
        exit(2);
    }

    setArray(&a, m_A, n_A);
    setArray(&b, m_B, n_B);

    matrix_A.m = m_A;
    matrix_B.m = m_B;
    matrix_A.n = n_A;
    matrix_B.n = n_B;
    matrix_A.elements = a;
    matrix_B.elements = b;
}
