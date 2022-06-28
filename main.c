/*--------------------------------------------------------------------*/
/* main.c                                                             */
/*--------------------------------------------------------------------*/

#include "matrix.h"
#include "reading.h"
#include "add.h"
#include "multiply.h"
#include "print.h"
#include <stdio.h>
#include <stdlib.h>

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
    int option = atoi(argv[5]);

    Matrix_t matrix_A, matrix_B;
    readMatrices(&matrix_A, &matrix_B, m_A, m_B, n_A, n_B);
    Matrix_t result;
    
    if (option == 0) {
        result = mat_add(matrix_A, matrix_B);
        printf("A + B = \n");
    }
    else if (option == 1) {
        result = mat_multiply(matrix_A, matrix_B);
        printf("A • B = \n");
    }
    printMatrix(result);

    return 0;
}