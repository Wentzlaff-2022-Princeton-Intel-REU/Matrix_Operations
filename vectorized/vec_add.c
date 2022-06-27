/*--------------------------------------------------------------------*/
/* vec_add.c                                                              */
/* Author: Manya Zhu                                       */
/*--------------------------------------------------------------------*/

// The method mat_add adds two mxn arrays and returns the result in an mxn array. 
// Both arrays must be of the same dimensions.

#include <stdlib.h>
#include <stdio.h>
#include "vec_add.h"

/*--------------------------------------------------------------------*/

Matrix_t vec_add(Matrix_t mat1, Matrix_t mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n) {
        exit(2);
    }

    int row = mat1.m;
    int column = mat1.n;
    size_t avl = row * column;

    Matrix_t resultingMatrix;
    resultingMatrix.m = row;
    resultingMatrix.n = column;

    double* addend1 = &mat1.elements;
    double* addend2 = &mat2.elements;

    vint32m1_t va, vb, vc;

    //resultingMatrix.elements  = (double*) malloc (sizeof(double) * row * column);

    for(size_t vl; vl = vsetvl_e32m1(avl) > 0; avl -= vl) {
        va = vle32_v_i32m1(addend1, vl);
        vb = vle32_v_i32m1(addend2, vl);
        vc = vadd_vv_i32m1(va, vb, vl);
        addend1 += vl;
        addend2 += vl;
    }

    resultingMatrix.elements = vc;
    
    /* for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++){
            // resultingMatrix.elements[i][j] = mat1.elements[i][j] + mat2.elements[i][j];
            *(resultingMatrix.elements + i*column + j) = *(mat1.elements + i*column + j) + *(mat2.elements + i*column + j);
        }
    }
    */
}