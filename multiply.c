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
    int r1= mat1.m;
    int c1 = mat1.n;
    int r2 = mat2.m;
    int c2 = mat2.n;

    Matrix_t resultingMatrix;
    resultingMatrix.m = r1;
    resultingMatrix.n = c2;
    resultingMatrix.elements  = (double*) malloc (sizeof(double) * r1 * c2);

    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++){
            *(resultingMatrix.elements + i*c2 + j) = 0;
            for (int k = 0; k < r2; k++){
                *(resultingMatrix.elements + i*c2 + j) += *(mat1.elements + i*c2 + k) + *(mat2.elements + k*c2 + j);
            }
        }
    }
    return resultingMatrix;
}