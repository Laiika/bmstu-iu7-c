#include <stdlib.h>
#include "check_sort.h"
#include "node.h"
#include "list.h"

START_TEST(test_sort_empty_list)
{
    node_t *head = NULL;

    head = sort(head, compare_int);
    ck_assert_ptr_eq(head, NULL);
}
END_TEST

START_TEST(test_sort_usual)
{
    node_t *head = NULL;
    int arr[6] = {11, 0, -4, 5, 3, 0}, i = 0;
    int res[6] = {-4, 0, 0, 3, 5, 11};

    head = list_nums_fill(arr, 6);

    if (head)
    {
        head = sort(head, compare_int);

        for (node_t *cur = head; cur; cur = cur->next, i++)
            ck_assert_int_eq(*(int*)cur->data, res[i]);

        ck_assert_int_eq(6, i);

        for (node_t *cur = head; cur; cur = cur->next)
            free(cur->data);

        list_free_all(head);
    }
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("sort");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_sort_empty_list);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_sort_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
