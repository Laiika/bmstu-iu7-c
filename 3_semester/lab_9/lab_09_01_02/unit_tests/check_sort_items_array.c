#include "check_sort_items_array.h"
#include "items.h"
#include "item.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>

#define EPS 1e-8

START_TEST(test_sort_items_array_dif_ro)
{
    size_t size = 3;
    item_t arr[3];
    int rc;

    arr[0].name = strdup("first");
    arr[0].weight = 100;
    arr[0].volume = 10.1;

    if (arr[0].name)
    {
        arr[1].name = strdup("second");
        arr[1].weight = 2;
        arr[1].volume = 20.1;

        if (arr[1].name)
        {
            arr[2].name = strdup("third");
            arr[2].weight = 30;
            arr[2].volume = 30.1;

            if (arr[2].name)
            {
                item_t arr2[3] = {{"second", 2, 20.1}, {"third", 30, 30.1}, {"first", 100, 10.1}};

                rc = sort_items_array(arr, size);

                if (MEMORY_ERROR != rc)
                {
                    ck_assert_int_eq(rc, EXIT_SUCCESS);

                    for (size_t i = 0; i < size; i++)
                    {
                        ck_assert_str_eq(arr[i].name, arr2[i].name);
                        ck_assert_float_eq_tol(arr[i].weight, arr2[i].weight, EPS);
                        ck_assert_float_eq_tol(arr[i].volume, arr2[i].volume, EPS);
                    }
                }
                
                free_item(arr + 2);
            }

            free_item(arr + 1);
        }

        free_item(arr + 0);
    }
}
END_TEST

START_TEST(test_sort_items_array_same_ro)
{
    size_t size = 3;
    item_t arr[3];
    int rc;

    arr[0].name = strdup("first");
    arr[0].weight = 100;
    arr[0].volume = 10.1;

    if (arr[0].name)
    {
        arr[1].name = strdup("second");
        arr[1].weight = 2;
        arr[1].volume = 20.1;

        if (arr[1].name)
        {
            arr[2].name = strdup("third");
            arr[2].weight = 100;
            arr[2].volume = 10.1;

            if (arr[2].name)
            {
                item_t arr2[3] = {{"second", 2, 20.1}, {"first", 100, 10.1}, {"third", 100, 10.1}};

                rc = sort_items_array(arr, size);

                if (MEMORY_ERROR != rc)
                {
                    ck_assert_int_eq(rc, EXIT_SUCCESS);

                    for (size_t i = 0; i < size; i++)
                    {
                        ck_assert_str_eq(arr[i].name, arr2[i].name);
                        ck_assert_float_eq_tol(arr[i].weight, arr2[i].weight, EPS);
                        ck_assert_float_eq_tol(arr[i].volume, arr2[i].volume, EPS);
                    }
                }
                
                free_item(arr + 2);
            }

            free_item(arr + 1);
        }

        free_item(arr + 0);
    }
}
END_TEST

Suite* sort_items_array_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort_items_array");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_items_array_dif_ro);
    tcase_add_test(tc_pos, test_sort_items_array_same_ro);

    suite_add_tcase(s, tc_pos);

    return s;
}
