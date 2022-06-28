/*--------------------------------------------------------------------*/
/* main.c                                                             */
/*--------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "reading.h"
#include "add.h"
#include "multiply.h"
#include "print.h"

/*--------------------------------------------------------------------*/

int main(int argc, char *argv[]) {

    if(argc != 6){
        fprintf(stderr, "Usage: %s 5 values needed\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int m_A = atoi(argv[1]);
    int n_A = atoi(argv[2]);
    int m_B = atoi(argv[3]);
    int n_B = atoi(argv[4]);
    int isAdd = atoi(argv[5]);

    Matrix_t matrix_A, matrix_B;
    readMatrices(&matrix_A, &matrix_B, m_A, m_B, n_A, n_B);
    Matrix_t result;
    
    if (isAdd == 1) {
        result = mat_add(matrix_A, matrix_B);
        printf("A + B = \n");
    }
    else if (isAdd == 0) {
        result = mat_multiply(matrix_A, matrix_B);
        printf("A • B = \n");
    }
    printMatrix(result);
    
    // free matrices
    free_mat(&matrix_A);
    free_mat(&matrix_B);
    free_mat(&result);

    return 0;
}