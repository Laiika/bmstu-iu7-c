#ifndef _MTR_MULT_H_
#define _MTR_MULT_H_

#include "matrix.h"
#include "errors.h"

int mtr_mult(mtr_t *result, mtr_t *a, mtr_t *b);
int mtr_exp(mtr_t *result, mtr_t *mtr, int exp);

#endif
