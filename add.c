/*--------------------------------------------------------------------*/
/* add.c                                                              */
/* Author: Mukund Ramakrishnan                                        */
/*--------------------------------------------------------------------*/

// The method addMatrices adds two mxn arrays and returns the result in an mxn array. 
// Both arrays must be of the same dimensions.

#include <stdlib.h>


Matrix_t mat_add (Matrix_t mat1, Matrix_t mat2){



int row = mat1.m;
int column = mat1.n;


Matrix_t resultingMatrix;
resultingMatrix.m = row;
resultingMatrix.n = column;

double result[row][column] = (double*) malloc (sizeof(double) * row * column);


for (int i = 0; i < sizeFirst; i++){
    for (int j = 0; j < sizeSecond; j++){
        result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
    }
}

return result;
}




