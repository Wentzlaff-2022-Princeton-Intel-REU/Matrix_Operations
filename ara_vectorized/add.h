#pragma once
/*------------------------------------------------------------*/
/* vec_add.h                                                  */
/*------------------------------------------------------------*/

#include "matrix.h"

/*------------------------------------------------------------*/

/* The add function takes in two matrices as input and returns
a matrix that is the sum of the two arguments */
void add(Matrix_t mat1, Matrix_t mat2, Matrix_t* resultingMatrix);
