#include "mtr_mult.h"
#include <stdlib.h>
#include "mtr_mem.h"

// функция для копирования матрицы из одной в другую
int mtr_copy(mtr_t *from, mtr_t *to)
{
    if (from->rows != to->rows || from->cols != to->cols)
        return SIZE_ERROR;
        
    for (size_t i = 0; i < from->rows; i++)
        for (size_t j = 0; j < from->rows; j++)
            to->ptrs[i][j] = from->ptrs[i][j];

    return EXIT_SUCCESS;
}

// функция для вычисления произведения двух матриц
int mtr_mult(mtr_t *result, mtr_t *a, mtr_t *b)
{
    if (a->cols != b->rows)
        return SIZE_ERROR;

    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < b->cols; j++)
        {
            result->ptrs[i][j] = 0;

            for (size_t k = 0; k < a->cols; k++)
                result->ptrs[i][j] += a->ptrs[i][k] * b->ptrs[k][j];
        }

    return EXIT_SUCCESS;
}

// функция для возведения матрицы в степень
int mtr_exp(mtr_t *result, mtr_t *mtr, int exp)
{
    if (result->rows != mtr->rows || result->cols != mtr->cols || mtr->rows != mtr->cols)
        return SIZE_ERROR;

    if (exp < 0)
        return EXP_ERROR;

    // степень равна 0
    if (0 == exp)
    {
        // делаем матрицу единичной
        for (size_t i = 0; i < mtr->rows; i++)
            for (size_t j = 0; j < mtr->rows; j++)
                if (i == j)
                    result->ptrs[i][j] = 1;
                else
                    result->ptrs[i][j] = 0;

        return EXIT_SUCCESS;
    }
    // степень равна 1
    if (1 == exp)
    {
        mtr_copy(mtr, result);
        return EXIT_SUCCESS;
    }

    mtr_t copy;

    copy.rows = mtr->rows;
    copy.cols = mtr->cols;

    if (MEMORY_ERROR == mtr_allocate(&copy))
        return MEMORY_ERROR;

    mtr_copy(mtr, &copy);

    for (size_t i = 1; i < exp; i++)
    {
        // умножаем полученный ранее результат на исходную матрицу
        mtr_mult(result, &copy, mtr);
        // копируем полученный результат
        mtr_copy(result, &copy);
    }

    mtr_free(&copy);
    return EXIT_SUCCESS;
}
