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
    resultingMatrix.elements = (int*) malloc (sizeof(int) * row * column);

    int* addend1 = mat1.elements;
    int* addend2 = mat2.elements;
    int* sum = resultingMatrix.elements;

    vint32m1_t va, vb, vc;

    for (size_t vl; (vl = vsetvl_e32m1(avl)) > 0; avl -= vl) {
        va = vle32_v_i32m1(addend1, vl);
        vb = vle32_v_i32m1(addend2, vl);
        vc = vadd_vv_i32m1(va, vb, vl);
        vse32_v_i32m1(sum, vc, vl);
        addend1 += vl;
        addend2 += vl;
        sum += vl;
    }

    return resultingMatrix;
}
