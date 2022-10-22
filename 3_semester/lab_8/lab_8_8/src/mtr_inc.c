#include "mtr_inc.h"
#include "mtr_mem.h"
#include <math.h>

// функция для добавления строк и столбцов в матрицу
int mtr_inc(mtr_t *mtr, size_t new_size)
{
    int rc;
    // не получилось увеличить размер матрицы
    if (EXIT_SUCCESS != (rc = mtr_inc_size(mtr, new_size, new_size)))
        return rc;

    // добавление строк
    while (mtr->rows < new_size)
    {
        for (size_t i = 0; i < mtr->cols; i++)
        {
            long mult = 1;
            // проходим по столбцу
            for (size_t j = 0; j < mtr->rows; j++)
                mult *= mtr->ptrs[j][i];
            // добавляем округленное вниз среднее геометрическое модулей элементов столбца в новую строку
            mtr->ptrs[mtr->rows][i] = (int)floor(pow(abs(mult), 1.0 / mtr->rows));
        }

        mtr->rows++;
    }
    // добавление столбцов
    if (mtr->cols < new_size)
    {
        for (size_t i = 0; i < mtr->rows; i++)
        {
            int min = mtr->ptrs[i][0];
            // проходим по строке
            for (size_t j = 1; j < mtr->cols; j++)
                if (min > mtr->ptrs[i][j])
                    min = mtr->ptrs[i][j];
            // добавляем минимальный элемент строки в новые столбцы
            for (size_t j = mtr->cols; j < new_size; j++)
                mtr->ptrs[i][j] = min;
        }

        mtr->cols = new_size;
    }

    return EXIT_SUCCESS;
}
