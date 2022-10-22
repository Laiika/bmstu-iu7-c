#include "check_mtr.h"
#include "matrix.h"
#include "errors.h"
#include <stdlib.h>
#include "mtr_mult.h"
#include "mtr_mem.h"

START_TEST(test_mtr_exp_bad_size)
{
    mtr_t mtr, result;
    int rc;

    mtr.rows = 3;
    mtr.cols = 2;
    result.rows = 3;
    result.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        if (EXIT_SUCCESS == mtr_allocate(&result))
        {
            for (size_t i = 0; i < mtr.rows; i++)
                for (size_t j = 0; j < mtr.cols; j++)
                    mtr.ptrs[i][j] = i + j;

            rc = mtr_exp(&result, &mtr, 3);
            ck_assert_int_eq(rc, SIZE_ERROR);

            mtr_free(&result);
        }

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_exp_neg_exp)
{
    mtr_t mtr, result;
    int rc;

    mtr.rows = 3;
    mtr.cols = 3;
    result.rows = 3;
    result.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        if (EXIT_SUCCESS == mtr_allocate(&result))
        {
            for (size_t i = 0; i < mtr.rows; i++)
                for (size_t j = 0; j < mtr.cols; j++)
                    mtr.ptrs[i][j] = i + j;

            rc = mtr_exp(&result, &mtr, -3);
            ck_assert_int_eq(rc, EXP_ERROR);

            mtr_free(&result);
        }

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_exp_usual)
{
    mtr_t mtr, result;
    int rc;

    mtr.rows = 3;
    mtr.cols = 3;
    result.rows = 3;
    result.cols = 3;
    int m[3][3] = {{30, 54, 78}, {54, 96, 138}, {78, 138, 198}};

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        if (EXIT_SUCCESS == mtr_allocate(&result))
        {
            for (size_t i = 0; i < mtr.rows; i++)
                for (size_t j = 0; j < mtr.cols; j++)
                    mtr.ptrs[i][j] = i + j;

            rc = mtr_exp(&result, &mtr, 3);

            if (MEMORY_ERROR != rc)
            {
                ck_assert_int_eq(rc, EXIT_SUCCESS);

                for (size_t i = 0; i < mtr.rows; i++)
                    for (size_t j = 0; j < mtr.cols; j++)
                        ck_assert_int_eq(m[i][j], result.ptrs[i][j]);
            }

            mtr_free(&result);
        }

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_exp_1)
{
    mtr_t mtr, result;
    int rc;

    mtr.rows = 3;
    mtr.cols = 3;
    result.rows = 3;
    result.cols = 3;
    int m[3][3] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        if (EXIT_SUCCESS == mtr_allocate(&result))
        {
            for (size_t i = 0; i < mtr.rows; i++)
                for (size_t j = 0; j < mtr.cols; j++)
                    mtr.ptrs[i][j] = i + j;

            rc = mtr_exp(&result, &mtr, 1);
            
            if (MEMORY_ERROR != rc)
            {
                ck_assert_int_eq(rc, EXIT_SUCCESS);

                for (size_t i = 0; i < mtr.rows; i++)
                    for (size_t j = 0; j < mtr.cols; j++)
                        ck_assert_int_eq(m[i][j], result.ptrs[i][j]);
            }

            mtr_free(&result);
        }

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_exp_0)
{
    mtr_t mtr, result;
    int rc;

    mtr.rows = 3;
    mtr.cols = 3;
    result.rows = 3;
    result.cols = 3;
    int m[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        if (EXIT_SUCCESS == mtr_allocate(&result))
        {
            for (size_t i = 0; i < mtr.rows; i++)
                for (size_t j = 0; j < mtr.cols; j++)
                    mtr.ptrs[i][j] = i + j;

            rc = mtr_exp(&result, &mtr, 0);
            
            if (MEMORY_ERROR != rc)
            {
                ck_assert_int_eq(rc, EXIT_SUCCESS);

                for (size_t i = 0; i < mtr.rows; i++)
                    for (size_t j = 0; j < mtr.cols; j++)
                        ck_assert_int_eq(m[i][j], result.ptrs[i][j]);
            }

            mtr_free(&result);
        }

        mtr_free(&mtr);
    }
}
END_TEST

Suite* mtr_exp_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("mtr_exp");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_mtr_exp_bad_size);
    tcase_add_test(tc_neg, test_mtr_exp_neg_exp);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mtr_exp_usual);
    tcase_add_test(tc_neg, test_mtr_exp_1);
    tcase_add_test(tc_neg, test_mtr_exp_0);

    suite_add_tcase(s, tc_pos);

    return s;
}
