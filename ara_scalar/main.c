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


    
    Matrix_t matrix_A, matrix_B;
    readMatrices(&matrix_A, &matrix_B);
    Matrix_t result;
    
    sum = add(matrix_A, matrix_B);
    printf("A + B = \n");
    printMatrix(sum);

    product = multiply(matrix_A, matrix_B);
    printf("A * B = \n");
    printMatrix(product);

    return 0;
}