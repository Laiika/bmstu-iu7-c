#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include "errors.h"

struct mtr
{
    double **ptrs;
    int rows;
    int cols;
};
typedef struct mtr mtr_t;

int mtr_allocate(mtr_t *mtr);
void mtr_free(mtr_t *mtr);
int mtr_read(FILE *in, mtr_t *mtr);
void mtr_print(FILE *out, mtr_t *mtr);
int mtr_sum(mtr_t *result, mtr_t *a, mtr_t *b);
int mtr_mult(mtr_t *result, mtr_t *a, mtr_t *b);
int mtr_calc_det(mtr_t *mtr, double *det);

#endif
