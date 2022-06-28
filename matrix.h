#pragma once
/*------------------------------------------------------------*/
/* matrix.h                                                   */
/*------------------------------------------------------------*/

/* A Matrix is a struct represented by a 2d array of doubles, the
number of rows (m), and the number of columns(n)*/
typedef struct Matrix {
    int m;
    int n;
    int32_t* elements;
} Matrix_t;