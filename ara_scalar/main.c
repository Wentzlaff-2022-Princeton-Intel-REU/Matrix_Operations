/*--------------------------------------------------------------------*/
/* main.c                                                             */
/*--------------------------------------------------------------------*/


#include "matrix.h"
#include "reading.h"
#include "add.h"
#include "multiply.h"
#include "print.h"

/*--------------------------------------------------------------------*/

int main(int argc, char *argv[]) {
    
    Matrix_t matrix_A, matrix_B;
    matrix_A.m = 2;
    matrix_A.n = 2;
    matrix_B.m = 2;
    matrix_B.n = 2;
    int32_t arr[4] = {1,1,1,1};
    int32_t arr2[4] = {1,1,1,1};
    matrix_A.elements = arr;
    matrix_B.elements = arr2;
    // readMatrices(&matrix_A, &matrix_B);

    
    printMatrix(matrix_A);
    printMatrix(matrix_B);

    // sum = add(matrix_A, matrix_B);

    printf("A + B = \n");
    printMatrix(add(matrix_A, matrix_B));
    //printMatrix(sum);

    printf("A * B = \n");
    printMatrix(multiply(matrix_A, matrix_B));

    return 0;
}