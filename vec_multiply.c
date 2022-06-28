/*--------------------------------------------------------------------*/
/* vec_multiply.c                                                     */
/*--------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <riscv_vector.h>
#include "vec_multiply.h"

/*--------------------------------------------------------------------*/

Matrix_t vec_multiply(Matrix_t mat1, Matrix_t mat2){
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

    vint32m1_t vb, vc;

    for(size_t i = 0; i < p; i++) {
        size_t avl = q;
        for (size_t vl; (vl = vsetvl_e32m1(avl)) > 0; avl -= vl) {
            vc = vmv_v_x_i32m1(0, vl);
            for (size_t j = 0; j < n; j++) {
                vb = vle32_v_i32m1(&mat2.elements[j * q + (q - avl)], vl);
                vc = vmacc_vx_i32m1(vc, mat1.elements[i * n + j], vb, vl);
            }
            vse32_v_i32m1(&resultingMatrix.elements[i * q + (q - avl)], vc, vl);
        }
    }

    return resultingMatrix;
}