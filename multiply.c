/*--------------------------------------------------------------------*/
/* multiply.c                                                         */
/* Author: Mukund Ramakrishnan                                        */
/*--------------------------------------------------------------------*/

// The method mat_multiply multiplies two matrices.  

#include <stdlib.h>
#include <stdio.h>
#include <multiply.h>

/*--------------------------------------------------------------------*/

Matrix_t mat_multiply (Matrix_t mat1, Matrix_t mat2){
    if (mat1.n != mat2.m) {
        exit(2);
    }

    int p = mat1.m;
    int n = mat1.n;
    int q = mat2.n;

    Matrix_t resultingMatrix;
    resultingMatrix.m = p;
    resultingMatrix.n = q;
    resultingMatrix.elements  = (double*) malloc (sizeof(double) * p * q);

    for (int i = 0; i < p; i++){
        for (int j = 0; j < q; j++){
            *(resultingMatrix.elements + i * q + j) = 0;
            for (int k = 0; k < n; k++){
                *(resultingMatrix.elements + i * q + j) += *(mat1.elements + i * q + k) * *(mat2.elements + k * q + j);
            }
        }
    }
    return resultingMatrix;
}