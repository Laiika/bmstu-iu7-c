#include "matrix.h"
#include <stdlib.h>
#include <math.h>

#define EPS 1e-8

// функция для выделения памяти под матрицу
int mtr_allocate(mtr_t *mtr)
{
    double *data;

    // выделение памяти под массив указателей на строки матрицы
    mtr->ptrs = malloc((mtr->rows + 1) * sizeof(double*));

    if (!mtr->ptrs)
        return MEMORY_ERROR;

    // выделение памяти под саму матрицу
    data = malloc(mtr->rows * mtr->cols * sizeof(double));

    if (!data)
    {
        free(mtr->ptrs);
        return MEMORY_ERROR;
    }

    for (int i = 0; i < mtr->rows; i++)
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

// функция для чтения матрицы
int mtr_read(FILE *in, mtr_t *mtr)
{
    // чтение размеров матрицы
    if (2 != fscanf(in, "%d %d", &(mtr->rows), &(mtr->cols)) || mtr->rows <= 0 || mtr->cols <= 0)
        return SIZE_ERROR;

    // выделение памяти под матрицу
    if (MEMORY_ERROR == mtr_allocate(mtr))
        return MEMORY_ERROR;

    // чтение матрицы
    for (size_t i = 0; i < mtr->rows; i++)
        for (size_t j = 0; j < mtr->cols; j++)
            if (1 != fscanf(in, "%lf", &mtr->ptrs[i][j]))
            {
                mtr_free(mtr);
                return READ_ERROR;
            }

    return EXIT_SUCCESS;
}

// функция для печати матрицы
void mtr_print(FILE *out, mtr_t *mtr)
{
    fprintf(out, "%d %d\n", mtr->rows, mtr->cols);

    for (size_t i = 0; i < mtr->rows; i++)
    {
        for (size_t j = 0; j < mtr->cols; j++)
        {
            fprintf(out, "%lf", mtr->ptrs[i][j]);

            if (j != mtr->cols - 1)
                fprintf(out, " ");
        }

        fprintf(out, "\n");
    }
}

// функция для вычисления суммы двух матриц
int mtr_sum(mtr_t *result, mtr_t *a, mtr_t *b)
{
    if (a->rows != b->rows || a->cols != b->cols)
        return SIZE_ERROR;

    for (size_t i = 0; i < a->rows; i++)
        for (size_t j = 0; j < b->cols; j++)
            result->ptrs[i][j] = a->ptrs[i][j] + b->ptrs[i][j];

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

// функция для вычисления определителя матрицы
int mtr_calc_det(mtr_t *mtr, double *det)
{
    if (mtr->rows != mtr->cols)
        return SIZE_ERROR;

    *det = 1.0;

    for (size_t j = 0; j < mtr->cols; j++)
    {
        double max = fabs(mtr->ptrs[j][j]);
        size_t row = j;

        for (size_t i = j + 1; i < mtr->rows; i++)
            if (max < fabs(mtr->ptrs[i][j]))
            {
                max = fabs(mtr->ptrs[i][j]);
                row = i;
            }

        if (max < EPS)
        {
            *det = 0.0;
            break;
        }
        
        if (j != row)
        {
            double *temp = mtr->ptrs[j];

            mtr->ptrs[j] = mtr->ptrs[row];
            mtr->ptrs[row] = temp;
            *det = -(*det);
        }

        for (int i = j + 1; i < mtr->rows; i++)
        {
            double m = mtr->ptrs[i][j] / mtr->ptrs[j][j];

            mtr->ptrs[i][j] = 0.0;
            
            for (size_t k = j + 1; k < mtr->cols; k++)
                mtr->ptrs[i][k] -= m * mtr->ptrs[j][k];
        }

        *det = (*det) * mtr->ptrs[j][j];
    }

    if (fabs(*det) < EPS)
        *det = 0.0;

    return EXIT_SUCCESS;
}
