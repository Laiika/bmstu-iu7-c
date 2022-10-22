#include "check_arr_lib.h"
#include <stdlib.h>
#include "arr_lib.h"

START_TEST(test_arr_copy_first_dst_len_is_less)
{
    int rc;
    size_t dst_len = 1, src_len = 5;
    int src[5] = {1, 2, 3, 4, 5};
    int dst[1];

    rc = arr_copy_first(src, src_len, dst, &dst_len);
    ck_assert_int_eq(rc, SIZE_ERROR);
    ck_assert_int_eq(dst_len, 5);
}
END_TEST

START_TEST(test_arr_copy_first_src_null)
{
    int rc;
    size_t dst_len = 1, src_len = 1;
    int dst[1];

    rc = arr_copy_first(NULL, src_len, dst, &dst_len);
    ck_assert_int_eq(rc, NULL_POINTER);
}
END_TEST

START_TEST(test_arr_copy_first_dst_len_null)
{
    int rc;
    size_t src_len = 5;
    int src[5] = {1, 2, 3, 4, 5};
    int dst[5];

    rc = arr_copy_first(src, src_len, dst, NULL);
    ck_assert_int_eq(rc, NULL_POINTER);
}
END_TEST

START_TEST(test_arr_copy_first_repets)
{
    int rc;
    size_t dst_len = 5, src_len = 7;
    int src[7] = {1, 2, 3, 2, 4, 55, 1};
    int dst[5] = {0};
    int res[5] = {1, 2, 3, 4, 55};

    rc = arr_copy_first(src, src_len, dst, &dst_len);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(dst_len, 5);

    for (size_t i = 0; i < dst_len; i++)
        ck_assert_int_eq(res[i], dst[i]);
}
END_TEST

START_TEST(test_arr_copy_first_no_repets)
{
    int rc;
    size_t dst_len = 4, src_len = 4;
    int src[4] = {1, 2, 3, 4};
    int dst[4] = {0};
    int res[4] = {1, 2, 3, 4};

    rc = arr_copy_first(src, src_len, dst, &dst_len);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(dst_len, 4);

    for (size_t i = 0; i < dst_len; i++)
        ck_assert_int_eq(res[i], dst[i]);
}
END_TEST

Suite* arr_copy_first_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("arr_copy_first");
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_arr_copy_first_dst_len_is_less);
    tcase_add_test(tc_neg, test_arr_copy_first_dst_len_null);
    tcase_add_test(tc_neg, test_arr_copy_first_src_null);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_arr_copy_first_repets);
    tcase_add_test(tc_pos, test_arr_copy_first_no_repets);
    suite_add_tcase(s, tc_pos);

    return s;
}
