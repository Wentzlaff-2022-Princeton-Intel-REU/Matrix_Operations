/*--------------------------------------------------------------------*/
/* add.c                                                              */
/* Author: Mukund Ramakrishnan                                        */
/*--------------------------------------------------------------------*/

// The method addMatrices adds two mxn arrays and returns the result in an mxn array. 
// Both arrays must be of the same dimensions.

#include <stdlib.h>


double[][] addMatrices (double[][] firstMatrix, double[][] secondMatrix){



int row = sizeof(firstMatrix) / sizeof(firstMatrix[0]);
int column = sizeof(firstMatrix[0]) / (row);

double result[row][column];

for (int i = 0; i < sizeFirst; i++){
    for (int j = 0; j < sizeSecond; j++){
        result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
    }
}

return result;
}




