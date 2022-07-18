/*--------------------------------------------------------------------*/
/* reading.c                                                          */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "reading.h"
/*--------------------------------------------------------------------*/


void readMatrices(Matrix_t* matrix_A, Matrix_t* matrix_B) {

    matrix_A->m = 2;
    matrix_A->n = 2;
    matrix_B->m = 2;
    matrix_B->n = 2;
    int32_t arr[4] = {1, 1, 1, 1};
    int32_t arr2[4] = {1, 1, 1, 1};
    matrix_A->elements = arr;
    matrix_B->elements = arr2;


}
