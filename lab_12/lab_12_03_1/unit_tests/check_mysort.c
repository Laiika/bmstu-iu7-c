#include "check_mysort.h"
#include "element.h"
#include <stdlib.h>

#ifdef DYNAMIC
#include "arr_dyn_lib.h"
#else
#include "arr_stat_lib.h"
#endif

START_TEST(test_mysort_bad_array_ptr)
{
    size_t nmemb = 10, size = sizeof(int);
    int rc;

    rc = mysort(NULL, nmemb, size, compare_int);
    ck_assert_int_eq(rc, INVALID_PARAM_ERROR);
}
END_TEST

START_TEST(test_mysort_bad_nmemb)
{
    int arr[3] = {0};
    size_t nmemb = 0, size = sizeof(int);
    int rc;

    rc = mysort(arr, nmemb, size, compare_int);
    ck_assert_int_eq(rc, INVALID_PARAM_ERROR);
}
END_TEST

START_TEST(test_mysort_bad_size)
{
    int arr[3] = {0};
    size_t nmemb = 3, size = 0;
    int rc;

    rc = mysort(arr, nmemb, size, compare_int);
    ck_assert_int_eq(rc, INVALID_PARAM_ERROR);
}
END_TEST

START_TEST(test_mysort_bad_compar)
{
    int arr[3] = {0};
    size_t nmemb = 3, size = sizeof(int);
    int rc;

    rc = mysort(arr, nmemb, size, NULL);
    ck_assert_int_eq(rc, INVALID_PARAM_ERROR);
}
END_TEST

START_TEST(test_mysort_usual_array)
{
    int arr[5] = {-4, 55, 34, 0, 29883};
    int arr2[5] = {-4, 0, 34, 55, 29883};
    size_t nmemb = 5, size = sizeof(int);
    int rc;

    rc = mysort(arr, nmemb, size, compare_int);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    for (size_t i = 0; i < nmemb; i++)
        ck_assert_int_eq(arr[i], arr2[i]);
}
END_TEST

START_TEST(test_mysort_one_element)
{
    int arr[1] = {-4};
    size_t nmemb = 1, size = sizeof(int);
    int rc;

    rc = mysort(arr, nmemb, size, compare_int);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(arr[0], -4);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("mysort");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_mysort_bad_array_ptr);
    tcase_add_test(tc_neg, test_mysort_bad_nmemb);
    tcase_add_test(tc_neg, test_mysort_bad_size);
    tcase_add_test(tc_neg, test_mysort_bad_compar);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mysort_usual_array);
    tcase_add_test(tc_pos, test_mysort_one_element);

    suite_add_tcase(s, tc_pos);

    return s;
}
