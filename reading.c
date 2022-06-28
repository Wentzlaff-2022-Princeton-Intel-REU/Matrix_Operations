/*--------------------------------------------------------------------*/
/* reading.c                                                          */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "reading.h"

/*--------------------------------------------------------------------*/

static void setArray(int32_t* array, int row, int col) {
    for (int i = 0; i < row; i++) {
            char temp;
        for (int j = 0; j < col; j++) {
            scanf("%d%c", &array[i * col + j], &temp);
            if (temp != ' ' && j < col - 1) {
                exit(2);
            }
        }
        if (temp != '\n') {
            exit(2);
        }
    }
}

void readMatrices(Matrix_t* matrix_A, Matrix_t* matrix_B, int m_A, int m_B, int n_A, int n_B) {
    int32_t* a = (int32_t*)malloc(sizeof(int32_t) * m_A * n_A);
    int32_t* b = (int32_t*)malloc(sizeof(int32_t) * m_B * n_B);
    if (a == NULL || b == NULL) {
        exit(2);
    }

    printf("Enter elements for matrix A:\n");
    setArray(a, m_A, n_A);
    printf("Enter elements for matrix B:\n");
    setArray(b, m_B, n_B);

    matrix_A->m = m_A;
    matrix_B->m = m_B;
    matrix_A->n = n_A;
    matrix_B->n = n_B;
    matrix_A->elements = a;
    matrix_B->elements = b;
}
