#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdlib.h>

struct mtr
{
    int **ptrs;
    size_t rows;
    size_t cols;
};
typedef struct mtr mtr_t;

#endif
