#include "check_arr_lib.h"
#include <stdlib.h>
#include "arr_lib.h"

START_TEST(test_arr_fill_fib_nums_arr_null)
{
    int rc;
    size_t n = 5;

    rc = arr_fill_fib_nums(NULL, n);
    ck_assert_int_eq(rc, NULL_POINTER);
}
END_TEST

START_TEST(test_arr_fill_fib_nums_n_is_0)
{
    int rc;
    size_t n = 0;
    int arr[3];

    rc = arr_fill_fib_nums(arr, n);
    ck_assert_int_eq(rc, SIZE_ERROR);
}
END_TEST


START_TEST(test_arr_fill_fib_nums_n_normal)
{
    int rc;
    size_t n = 22;
    int arr[22];

    rc = arr_fill_fib_nums(arr, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    ck_assert_int_eq(arr[0], 0);
    ck_assert_int_eq(arr[1], 1);

    for (size_t i = 2; i < n; i++)
        ck_assert_int_eq(arr[i], arr[i - 1] + arr[i - 2]);
}
END_TEST

Suite* arr_fill_fib_nums_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("arr_fill_fib_nums");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_arr_fill_fib_nums_arr_null);
    tcase_add_test(tc_neg, test_arr_fill_fib_nums_n_is_0);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_arr_fill_fib_nums_n_normal);
    suite_add_tcase(s, tc_pos);

    return s;
}
