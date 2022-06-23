/*------------------------------------------------------------*/
/* main.c                                                     */
/* Author: Dara Oseyemi                                       */
/*------------------------------------------------------------*/

#include "matrix.h"
#include "reading.h"
#include "add.h"
#include "multiply.h"
#include "print.h"

/*------------------------------------------------------------*/

int main(int argc, char *argv[]) {
    int m_A = argv[1];
    int n_A = argv[2];
    int m_B = argv[3];
    int n_B = argv[4];
    bool option = argv[5];

    Matrix_t matrix_A, matrix_B;
    readMatrices(&matrix_A, &matrix_B, m_A, m_B, n_A, n_B);
    
    Matrix_t result = (option && mat_add(matrix_A, matrix_B)) || (!option && mat_multiply(matrix_A, matrix_B));
    printMatrix(result);

    return 0;
}