#include "mtr_in_out.h"
#include "mtr_mem.h"
#include <stdio.h>
#include <stdlib.h>

// функция для чтения матрицы
int mtr_read(mtr_t *mtr)
{
    int rows, cols;
    // чтение размеров матрицы
    if (2 != scanf("%d %d", &rows, &cols) || rows <= 0 || cols <= 0)
        return SIZE_ERROR;

    mtr->rows = rows;
    mtr->cols = cols;

    // выделение памяти под матрицу
    if (MEMORY_ERROR == mtr_allocate(mtr))
        return MEMORY_ERROR;

    // чтение матрицы
    for (size_t i = 0; i < mtr->rows; i++)
        for (size_t j = 0; j < mtr->cols; j++)
            if (1 != scanf("%d", &mtr->ptrs[i][j]))
            {
                mtr_free(mtr);
                return READ_ERROR;
            }

    return EXIT_SUCCESS;
}

// функция для вывода матрицы
void mtr_print(mtr_t *mtr)
{
    for (size_t i = 0; i < mtr->rows; i++)
    {
        for (size_t j = 0; j < mtr->cols; j++)
            printf("%d ", mtr->ptrs[i][j]);

        printf("\n");
    }
}
