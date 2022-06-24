#pragma once

/*------------------------------------------------------------*/
/* matrix.h                                                   */
/* Author: Dara Oseyemi                                       */
/*------------------------------------------------------------*/

#include <riscv_vector.h>

/*------------------------------------------------------------*/
/* A Matrix is a struct represented by a 2d array of int vectors,
the number of rows (m), and the number of columns(n) */
typedef struct Matrix {
    int m;
    int n;
    vint64m1_t* elements;
} Matrix_t;