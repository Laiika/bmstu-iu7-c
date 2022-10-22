#include "check_mtr.h"
#include "matrix.h"
#include "errors.h"
#include <stdlib.h>

#define EPS 1e-8

START_TEST(test_mtr_mult_bad_size)
{
    mtr_t mtr1, mtr2, result;
    int rc;

    mtr1.rows = 3;
    mtr1.cols = 3;
    mtr2.rows = 2;
    mtr2.cols = 3;
    result.rows = 3;
    result.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr1))
    {
        if (EXIT_SUCCESS == mtr_allocate(&mtr2))
        {
            if (EXIT_SUCCESS == mtr_allocate(&result))
            {
                for (size_t i = 0; i < mtr1.rows; i++)
                    for (size_t j = 0; j < mtr1.cols; j++)
                        mtr1.ptrs[i][j] = i + j;

                for (size_t i = 0; i < mtr2.rows; i++)
                    for (size_t j = 0; j < mtr2.cols; j++)
                        mtr2.ptrs[i][j] = i + j;

                rc = mtr_mult(&result, &mtr1, &mtr2);
                ck_assert_int_eq(rc, SIZE_ERROR);

                mtr_free(&result);
            }

            mtr_free(&mtr2);
        }

        mtr_free(&mtr1);
    }
}
END_TEST

START_TEST(test_mtr_mult_usual)
{
    mtr_t mtr1, mtr2, result;
    int rc;

    mtr1.rows = 2;
    mtr1.cols = 3;
    mtr2.rows = 3;
    mtr2.cols = 4;
    result.rows = 2;
    result.cols = 4;
    double m[2][4] = {{5, 11, 17, 23}, {8, 20, 32, 44}};

    if (EXIT_SUCCESS == mtr_allocate(&mtr1))
    {
        if (EXIT_SUCCESS == mtr_allocate(&mtr2))
        {
            if (EXIT_SUCCESS == mtr_allocate(&result))
            {
                for (size_t i = 0; i < mtr1.rows; i++)
                    for (size_t j = 0; j < mtr1.cols; j++)
                        mtr1.ptrs[i][j] = i + j;

                for (size_t i = 0; i < mtr2.rows; i++)
                    for (size_t j = 0; j < mtr2.cols; j++)
                        mtr2.ptrs[i][j] = i + 2 * j;

                rc = mtr_mult(&result, &mtr1, &mtr2);
                ck_assert_int_eq(rc, EXIT_SUCCESS);

                for (size_t i = 0; i < mtr1.rows; i++)
                    for (size_t j = 0; j < mtr2.cols; j++)
                        ck_assert_double_eq_tol(m[i][j], result.ptrs[i][j], EPS);

                mtr_free(&result);
            }

            mtr_free(&mtr2);
        }

        mtr_free(&mtr1);
    }
}
END_TEST

Suite* mtr_mult_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("mtr_mult");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_mtr_mult_bad_size);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mtr_mult_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
