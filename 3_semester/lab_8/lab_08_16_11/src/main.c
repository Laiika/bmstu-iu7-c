#include "matrix.h"
#include <stdlib.h>
#include "errors.h"
#include <string.h>

int main(int argc, char **argv)
{
    if (4 != argc && 5 != argc)
        return ARGS_ERROR;

    FILE *in1 = fopen(argv[2], "r");
    mtr_t mtr1;
    int rc = EXIT_SUCCESS;

    if (!in1)
        return ARGS_ERROR;

    // чтение первой матрицы
    if (EXIT_SUCCESS != (rc = mtr_read(in1, &mtr1)))
    {
        fclose(in1);
        return rc;
    }

    fclose(in1);

    if (5 == argc)
    {
        FILE *in2 = fopen(argv[3], "r");
        mtr_t mtr2, result;

        if (!in2)
        {
            mtr_free(&mtr1);
            return FILE_ERROR;
        }
        // чтение второй матрицы
        if (EXIT_SUCCESS != (rc = mtr_read(in2, &mtr2)))
        {
            fclose(in2);
            mtr_free(&mtr1);
            return rc;
        }

        fclose(in2);
        FILE *out = fopen(argv[4], "w");

        if (!out)
        {
            mtr_free(&mtr1);
            mtr_free(&mtr2);
            return FILE_ERROR;
        }

        result.rows = mtr1.rows;
        result.cols = mtr2.cols;

        if (EXIT_SUCCESS != (rc = mtr_allocate(&result)))
        {
            mtr_free(&mtr1);
            mtr_free(&mtr2);
            fclose(out);
            return rc;
        }

        if (0 == strcmp(argv[1], "a"))
        {
            if (EXIT_SUCCESS == (rc = mtr_sum(&result, &mtr1, &mtr2)))
                mtr_print(out, &result);
        }
        else if (0 == strcmp(argv[1], "m"))
        {
            if (EXIT_SUCCESS == (rc = mtr_mult(&result, &mtr1, &mtr2)))
                mtr_print(out, &result);
        }
        else
            rc = ARGS_ERROR;

        mtr_free(&mtr1);
        mtr_free(&mtr2);
        mtr_free(&result);
        fclose(out);
    }
    else if (4 == argc && 0 == strcmp(argv[1], "o"))
    {
        FILE *out = fopen(argv[3], "w");
        double det;

        if (!out)
        {
            mtr_free(&mtr1);
            return FILE_ERROR;
        }

        if (EXIT_SUCCESS == (rc = mtr_calc_det(&mtr1, &det)))
            fprintf(out, "%lf\n", det);

        mtr_free(&mtr1);
        fclose(out);
    }
    else
    {
        mtr_free(&mtr1);
        rc = ARGS_ERROR;
    }

    return rc;
}
