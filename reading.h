#pragma once
/*------------------------------------------------------------*/
/* reading.h                                                  */
/*------------------------------------------------------------*/

#include "matrix.h"

/*------------------------------------------------------------*/
// frees the elements in a matrix
void free_mat(*Matrix_t mat);

// initializes matrices A and B
void readMatrices(Matrix_t* matrix_A, Matrix_t* matrix_B, int m_A, int m_B,
int n_A, int n_B);