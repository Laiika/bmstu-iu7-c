#include <stdlib.h>
#include "check_find.h"
#include "node.h"
#include "list.h"

START_TEST(test_find_empty_list)
{
    node_t *head = NULL;
    int *data = malloc(sizeof(int));

    if (data)
    {
        *data = 5;

        node_t *elem = find(head, data, compare_int);
        ck_assert_ptr_eq(elem, NULL);
        free(data);
    }
}
END_TEST

START_TEST(test_find_not_found_data)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4};

    if (data)
    {
        *data = 5;
        head = list_nums_fill(arr, 5);

        if (head)
        {
            elem = find(head, data, compare_int);
            ck_assert_ptr_eq(elem, NULL);

            for (node_t *cur = head; cur; cur = cur->next)
                free(cur->data);

            list_free_all(head);
        }

        free(data);
    }
}
END_TEST

START_TEST(test_find_found_data)
{
    node_t *head = NULL, *elem = NULL, *res = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4};

    if (data)
    {
        *data = 3;
        head = list_nums_fill(arr, 5);

        if (head)
        {
            res = head;

            for (size_t i = 0; res && i < 3; i++)
                res = res->next;
 
            if (res)
            {
                elem = find(head, data, compare_int);
                ck_assert_ptr_eq(elem, res);
            }

            for (node_t *cur = head; cur; cur = cur->next)
                free(cur->data);

            list_free_all(head);
        }
        
        free(data);
    }
}
END_TEST

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("find");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_find_empty_list);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_find_not_found_data);
    tcase_add_test(tc_pos, test_find_found_data);

    suite_add_tcase(s, tc_pos);

    return s;
}
