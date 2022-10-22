#include "mtr_cut.h"
#include <stdlib.h>

// функция для поиска минимального элемента в столбце
int get_min_in_column(mtr_t *mtr, size_t column, size_t *row)
{
    int min = mtr->ptrs[0][column];
    *row = 0;

    for (size_t i = 1; i < mtr->rows; i++)
        if (min >= mtr->ptrs[i][column])
        {
            min = mtr->ptrs[i][column];
            *row = i;
        }

    return min;
}

// функция для нахождения строки и столбца с последним минимальным элементом при обходе по столбцам
void mtr_find_min(mtr_t *mtr, size_t *min_r, size_t *min_col)
{
    *min_col = 0;
    size_t row;
    int min = get_min_in_column(mtr, *min_col, min_r), cur;

    for (size_t i = 1; i < mtr->cols; i++) 
    {
        // минимальный элемент в текущем столбце
        cur = get_min_in_column(mtr, i, &row);
        // текущий элемент - последний минимальный
        if (min >= cur)
        {
            min = cur;
            *min_r = row;
            *min_col = i;
        }
    }
}

// функция для удаления строк и столбцов из матрицы
void mtr_cut(mtr_t *mtr)
{
    // удаление лишних столбцов
    while (mtr->rows < mtr->cols)
    {
        size_t min_r, min_col;
        // находим строку и столбец с минимальным элементом
        mtr_find_min(mtr, &min_r, &min_col);
        // удаляем этот столбец
        for (size_t i = min_col; i < mtr->cols - 1; i++) 
            for (size_t j = 0; j < mtr->rows; j++)
                mtr->ptrs[j][i] = mtr->ptrs[j][i + 1];

        mtr->cols--;
    }
    // удаление лишних строк
    while (mtr->rows > mtr->cols)
    {
        size_t min_r, min_col;
        // находим строку и столбец с минимальным элементом
        mtr_find_min(mtr, &min_r, &min_col);
        // удаляем эту строку
        for (size_t i = min_r; i < mtr->rows - 1; i++) 
            mtr->ptrs[i] = mtr->ptrs[i + 1];

        mtr->ptrs[mtr->rows - 1] = mtr->ptrs[mtr->rows];
        mtr->rows--;
    }
}
