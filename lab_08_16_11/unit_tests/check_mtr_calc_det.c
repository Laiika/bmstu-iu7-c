#include "check_mtr.h"
#include "matrix.h"
#include "errors.h"
#include <stdlib.h>

#define EPS 1e-8

START_TEST(test_mtr_calc_det_bad_size)
{
    mtr_t mtr;
    double det;
    int rc;

    mtr.rows = 3;
    mtr.cols = 2;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                mtr.ptrs[i][j] = i + j;

        rc = mtr_calc_det(&mtr, &det);
        ck_assert_int_eq(rc, SIZE_ERROR);
        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_calc_det_usual)
{
    mtr_t mtr;
    double det;
    int rc;

    mtr.rows = 3;
    mtr.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                mtr.ptrs[i][j] = 1;

        mtr.ptrs[0][0] = 6;
        mtr.ptrs[2][2] = 5.5;

        rc = mtr_calc_det(&mtr, &det);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_double_eq_tol(det, 22.5, EPS);

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_calc_det_0)
{
    mtr_t mtr;
    double det;
    int rc;

    mtr.rows = 3;
    mtr.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                mtr.ptrs[i][j] = i + j;

        rc = mtr_calc_det(&mtr, &det);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_double_eq_tol(det, 0.0, EPS);

        mtr_free(&mtr);
    }
}
END_TEST

Suite* mtr_calc_det_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("mtr_calc_det");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_mtr_calc_det_bad_size);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mtr_calc_det_usual);
    tcase_add_test(tc_pos, test_mtr_calc_det_0);

    suite_add_tcase(s, tc_pos);

    return s;
}
