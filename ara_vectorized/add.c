/*--------------------------------------------------------------------*/
/* vec_add.c                                                          */
/*--------------------------------------------------------------------*/

// The method mat_add adds two mxn arrays and returns the result in an mxn array. 
// Both arrays must be of the same dimensions.


#include "add.h"
#include "matrix.h"
#include "printf.h"

/*--------------------------------------------------------------------*/

void add(Matrix_t mat1, Matrix_t mat2, Matrix_t *resultingMatrix) {

    int row = mat1.m;
    int column = mat1.n;
    size_t avl = row * column;

    resultingMatrix->m = row;
    resultingMatrix->n = column;
    
    int32_t* addend1 = mat1.elements;
    int32_t* addend2 = mat2.elements;
    int32_t* sum = resultingMatrix->elements;

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
}
