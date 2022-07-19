/*--------------------------------------------------------------------*/
/* add.c                                                              */
/*--------------------------------------------------------------------*/

// The method mat_add adds two mxn arrays and returns the result in an mxn array. 
// Both arrays must be of the same dimensions.

#include <stdlib.h>
#include <stdio.h>
#include "add.h"

/*--------------------------------------------------------------------*/

Matrix_t add(Matrix_t mat1, Matrix_t mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n) {
        exit(2);
    }

    int row = mat1.m;
    int column = mat1.n;

    Matrix_t resultingMatrix;
    resultingMatrix.m = row;
    resultingMatrix.n = column;
    resultingMatrix.elements  = (int32_t*) malloc (sizeof(int32_t) * row * column);

    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            // resultingMatrix.elements[i][j] = mat1.elements[i][j] + mat2.elements[i][j];
            *(resultingMatrix.elements + i*column + j) = *(mat1.elements + i*column + j) + *(mat2.elements + i*column + j);
        }
    }

    return resultingMatrix;
}




