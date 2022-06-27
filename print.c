/*--------------------------------------------------------------------*/
/* print.c                                                            */
/* Author: Dara Oseyemi                                               */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "print.h"
#include "matrix.h"

/*--------------------------------------------------------------------*/

void printMatrix(Matrix_t mat) {
    int column = mat.n;
    for (int i = 0; i < mat.m; i++) {
        printf("[ ");
        for (int j = 0; j < mat.n; j++) {
            printf("%d ", mat.elements[i* column + j]);
        }
        printf("]\n");
    }
}
