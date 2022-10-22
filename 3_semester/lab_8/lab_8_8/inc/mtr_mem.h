#ifndef _MTR_MEM_H_
#define _MTR_MEM_H_

#include "matrix.h"
#include "errors.h"
#include <stdlib.h>

int mtr_allocate(mtr_t *mtr);
void mtr_free(mtr_t *mtr);
int mtr_inc_size(mtr_t *mtr, size_t new_rows, size_t new_cols);

#endif
