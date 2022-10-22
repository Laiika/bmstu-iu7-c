#include "mtr_mem.h"
#include <stdlib.h>

// функция для выделения памяти под матрицу
int mtr_allocate(mtr_t *mtr)
{
    int *data;

    // выделение памяти под массив указателей на строки матрицы
    mtr->ptrs = malloc((mtr->rows + 1) * sizeof(int*));

    if (!mtr->ptrs)
        return MEMORY_ERROR;

    // выделение памяти под саму матрицу
    data = malloc(mtr->rows * mtr->cols * sizeof(int));

    if (!data)
    {
        free(mtr->ptrs);
        return MEMORY_ERROR;
    }

    for (size_t i = 0; i < mtr->rows; i++)
        mtr->ptrs[i] = data + i * mtr->cols;

    mtr->ptrs[mtr->rows] = data;
    return EXIT_SUCCESS;
}

// функция для освобождения памяти из под матрицы
void mtr_free(mtr_t *mtr)
{
    free(mtr->ptrs[mtr->rows]);
    free(mtr->ptrs);
}

// функция для увеличения размера матрицы
int mtr_inc_size(mtr_t *mtr, size_t new_rows, size_t new_cols)
{
    if (mtr->rows > new_rows || mtr->cols > new_cols)
        return SIZE_ERROR;

    // выделение памяти под саму матрицу
    int *temp_data = malloc(new_rows * new_cols * sizeof(int));

    if (!temp_data)
        return MEMORY_ERROR;
   
    // копирование элементов матрицы
    for (size_t i = 0; i < mtr->rows; i++)
        for (size_t j = 0; j < mtr->cols; j++)
            temp_data[i * new_cols + j] = mtr->ptrs[i][j];

    // выделение памяти под массив указателей на строки матрицы
    int **temp_ptrs = malloc((new_rows + 1) * sizeof(int*));

    if (!temp_ptrs)
    {
        free(temp_data);
        return MEMORY_ERROR;
    }

    // освобождение памяти прежней матрицы
    mtr_free(mtr);

    mtr->ptrs = temp_ptrs;

    for (size_t i = 0; i < new_rows; i++)
        mtr->ptrs[i] = temp_data + i * new_cols;

    mtr->ptrs[new_rows] = temp_data;
    return EXIT_SUCCESS;
}
