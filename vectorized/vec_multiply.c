/*--------------------------------------------------------------------*/
/* vec_multiply.c                                                     */
/* Author: Dara Oseyemi                                               */
/*--------------------------------------------------------------------*/

// The method mat_multiply multiplies two matrices.  

#include <stdlib.h>
#include <stdio.h>
#include "vec_multiply.h"

/*--------------------------------------------------------------------*/

static int32_t* transpose(Matrix_t mat) {
    int32_t* trans_arr = (int32_t*) malloc (sizeof(int32_t) * mat.m * mat.n);

    for (int row = 0; row < mat.m; row++) {
        for (int col = 0; col < mat.n; col++) {
            trans_arr[col * mat.m + row] = mat.elements[row * mat.n + col];
        }
    }

    return trans_arr;
}

Matrix_t mat_multiply(Matrix_t mat1, Matrix_t mat2){
    if (mat1.n != mat2.m) {
        exit(2);
    }

    int p = mat1.m;
    int n = mat1.n;
    int q = mat2.n;
    int avl = p * q;

    Matrix_t resultingMatrix;
    resultingMatrix.m = p;
    resultingMatrix.n = q;
    resultingMatrix.elements  = (int32_t*) malloc (sizeof(int32_t) * avl);

    int32_t* addend1 = mat1.elements;
    int32_t* addend2 = transpose(mat2);
    int32_t* sum = resultingMatrix.elements;

    vint32m1_t va, vb, vc;

    for(size_t vl; vl = vsetvl_e32m1(avl) > 0; avl -= vl) {
        va = vle32_v_i32m1(addend1, vl);
        vb = vle32_v_i32m1(addend2, vl);
        vc = vmacc_vv_i32m1(vc, va, vb, vl);
        vse32_v_i32m1(sum, vc, vl);
        addend1 += vl;
        addend2 += vl;
        sum += vl;
    }
    
    return resultingMatrix;
}