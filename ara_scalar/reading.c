/*--------------------------------------------------------------------*/
/* reading.c                                                          */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "reading.h"

/*--------------------------------------------------------------------*/


void readMatrices(Matrix_t* matrix_A, Matrix_t* matrix_B, int m_A, int m_B, int n_A, int n_B) {
   
    if (a == NULL || b == NULL) {
        exit(2);
    }

    matrix_A->m = 2;
    matrix_A->n = 2;
    matrix_B->m = 2;
    matrix_B->n = 2;
    matrix_A->elements = {1, 1, 2, 2};
    matrix_B->elements = {1, 1, 2, 2};
}
