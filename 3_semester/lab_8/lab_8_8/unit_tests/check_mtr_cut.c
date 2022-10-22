#include "check_mtr.h"
#include "matrix.h"
#include <stdlib.h>
#include "mtr_cut.h"
#include "mtr_mem.h"

START_TEST(test_mtr_cut_square_mtr)
{
    mtr_t mtr;
    int m[3][3] = {{0, 1, 2}, {1, 2 , 3}, {2, 3, 4}};

    mtr.rows = 3;
    mtr.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                mtr.ptrs[i][j] = i + j;

        mtr_cut(&mtr);

        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                ck_assert_int_eq(m[i][j], mtr.ptrs[i][j]);

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_cut_del_rows)
{
    mtr_t mtr;
    int m[3][3] = {{1, 2, 3}, {2, 3, 4}, {3, 4, 5}};

    mtr.rows = 5;
    mtr.cols = 3;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                mtr.ptrs[i][j] = i + j;

        mtr.ptrs[4][0] = 0;
        mtr.ptrs[4][1] = 1;
        mtr.ptrs[4][2] = 2;

        mtr_cut(&mtr);

        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                ck_assert_int_eq(m[i][j], mtr.ptrs[i][j]);

        mtr_free(&mtr);
    }
}
END_TEST

START_TEST(test_mtr_cut_del_cols)
{
    mtr_t mtr;
    int m[3][3] = {{2, 3, 4}, {3, 4, 5}, {4, 5, 6}};

    mtr.rows = 3;
    mtr.cols = 5;

    if (EXIT_SUCCESS == mtr_allocate(&mtr))
    {
        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                mtr.ptrs[i][j] = i + j;

        mtr_cut(&mtr);

        for (size_t i = 0; i < mtr.rows; i++)
            for (size_t j = 0; j < mtr.cols; j++)
                ck_assert_int_eq(m[i][j], mtr.ptrs[i][j]);

        mtr_free(&mtr);
    }
}
END_TEST

Suite* mtr_cut_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mtr_cut");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mtr_cut_square_mtr);
    tcase_add_test(tc_pos, test_mtr_cut_del_rows);
    tcase_add_test(tc_pos, test_mtr_cut_del_cols);

    suite_add_tcase(s, tc_pos);

    return s;
}
