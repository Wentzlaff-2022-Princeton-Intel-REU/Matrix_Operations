/*--------------------------------------------------------------------*/
/* main.c                                                             */
/*--------------------------------------------------------------------*/


#include "matrix.h"
#include "add.h"
#include "multiply.h"
#include "print.h"
#include "runtime.h"

/*--------------------------------------------------------------------*/

int main() {
    
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

    Matrix_t resultingMatrix;
    int32_t arr3[4];
    resultingMatrix.elements = arr3;

    printf("Vector Addition: \n");

    printMatrix(matrix_A);
    printf("\n");
    printMatrix(matrix_B);

    
    start_timer();
    add(matrix_A, matrix_B, &resultingMatrix);
    stop_timer();
    int64_t cycle_time = get_timer();

    printMatrix(resultingMatrix);

    printf("Runtime (cycles): %x\n", cycle_time);

    Matrix_t product;
    int32_t arr4[4];
    product.elements = arr4;

    printf("Vector Multiplication: ");

    printMatrix(matrix_A);
    printf("\n");
    printMatrix(matrix_B);
    
    start_timer();
    multiply(matrix_A, matrix_B, &product);
    stop_timer();
    int64_t cycle_timeb = get_timer();
    printMatrix(product);

    printf("Runtime (cycles): %x\n", cycle_timeb);

    return 0;
}
