/*--------------------------------------------------------------------*/
/* vec_multiply.c                                                     */
/*--------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <riscv_vector.h>
#include "vec_multiply.h"

/*--------------------------------------------------------------------*/

Matrix_t vec_multiply(Matrix_t mat1, Matrix_t mat2){
    // check that col size of mat1 is same as row size of mat2
    if (mat1.n != mat2.m) {
        exit(2);
    }

    // p = mat1 row size, n mat1 col size, q mat2 col size
    int p = mat1.m;
    int n = mat1.n;
    int q = mat2.n;
    // active vector length is number of elements in product matrix
    int res_matrix_size = p * q;

    // init result matrix, malloc the elements 
    Matrix_t resultingMatrix;
    resultingMatrix.m = p;
    resultingMatrix.n = q;
    resultingMatrix.elements  = (int32_t*) malloc (sizeof(int32_t) * res_matrix_size);

    vint32m1_t vb, vc;
    
    // iter through rows of mat1
    for(size_t i = 0; i < p; i++) {
        // set vector length to be mat2 col
        size_t avl = q;
        // find the longest vl possible for the avl we have left
        for (size_t vl; (vl = vsetvl_e32m1(avl)) > 0; avl -= vl) {
            // first clear vc to hold all 0s
            vc = vmv_v_x_i32m1(0, vl);
            // for each col of mat1
            for (size_t j = 0; j < n; j++) {
                // load the row of mat2 up to vl for this iter. 
                vb = vle32_v_i32m1(&mat2.elements[j * q + (q - avl)], vl);
                // use vector multiply and accumulate in vector vc
                vc = vmacc_vx_i32m1(vc, mat1.elements[i * n + j], vb, vl);
            }
            // once the whole rol of mat` has been iterated through, save the vc register 
            // to the correct location in memory at resultingMatrix
            vse32_v_i32m1(&resultingMatrix.elements[i * q + (q - avl)], vc, vl);
        }
    }

    return resultingMatrix;
}