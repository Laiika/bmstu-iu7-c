#include <stdlib.h>
#include "errors.h"
#include <stdio.h>
#include "mtr_mem.h"
#include "mtr_in_out.h"
#include "mtr_cut.h"
#include "mtr_inc.h"
#include "mtr_mult.h"
#include "matrix.h"

int main(void)
{
    mtr_t a, b;
    int rc;
    
    // чтение матрицы А
    if (EXIT_SUCCESS != (rc = mtr_read(&a)))
        return rc;
    // чтение матрицы В
    if (EXIT_SUCCESS != (rc = mtr_read(&b)))
    {
        mtr_free(&a);
        return rc;
    }

    // удаление строк и столбцов в матрице А
    mtr_cut(&a);
    // удаление строк и столбцов в матрице В
    mtr_cut(&b);

    // увеличиваем матрицу В
    if (a.rows > b.rows)
        rc = mtr_inc(&b, a.rows);
    // увеличиваем матрицу А
    else if (a.rows < b.rows)
        rc = mtr_inc(&a, b.rows);

    if (EXIT_SUCCESS == rc)
    {
        int a_exp, b_exp;
        size_t new_size = a.rows;
        // чтение степеней
        if (2 == scanf("%d %d", &a_exp, &b_exp) && a_exp >= 0 && b_exp >= 0)
        {
            mtr_t res;

            res.rows = new_size;
            res.cols = new_size;

            if (EXIT_SUCCESS == (rc = mtr_allocate(&res)))
            {
                // возведение в степень матрицы А
                if (EXIT_SUCCESS == (rc = mtr_exp(&res, &a, a_exp)))
                    // возведение в степень матрицы В
                    if (EXIT_SUCCESS == (rc = mtr_exp(&a, &b, b_exp)))
                    {
                        // умножение результатов
                        if (EXIT_SUCCESS == (rc = mtr_mult(&b, &res, &a)))
                            mtr_print(&b);
                    }

                mtr_free(&res);
            }
        }
        else
            rc = READ_ERROR;
    }

    mtr_free(&a);
    mtr_free(&b);
    return rc;
}
