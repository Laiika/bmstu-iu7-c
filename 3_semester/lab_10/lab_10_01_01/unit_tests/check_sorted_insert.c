#include <stdlib.h>
#include "check_sorted_insert.h"
#include "node.h"
#include "list.h"

START_TEST(test_sorted_insert_empty_list)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));

    if (data)
    {
        *data = 5;
        elem = node_create(data);

        if (elem)
        {
            sorted_insert(&head, elem, compare_int);
            ck_assert_ptr_eq(head, elem);
            ck_assert_ptr_eq(head->next, NULL);
            free(elem);
        }

        free(data);
    }
}
END_TEST

START_TEST(test_sorted_insert_to_start)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4}, i = 0;
    int res[6] = {-9, 0, 1, 2, 3, 4};

    if (data)
    {
        *data = -9;
        elem = node_create(data);

        if (elem)
        {
            head = list_nums_fill(arr, 5);

            if (head)
            {
                sorted_insert(&head, elem, compare_int);

                for (node_t *cur = head; cur; cur = cur->next, i++)
                    ck_assert_int_eq(*(int*)cur->data, res[i]);

                ck_assert_int_eq(6, i);

                for (node_t *cur = head; cur; cur = cur->next)
                    free(cur->data);

                list_free_all(head);
            }
            else
            {
                free(elem);
                free(data);
            }
        }
        else
            free(data);
    }
}
END_TEST

START_TEST(test_sorted_insert_to_end)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4}, i = 0;
    int res[6] = {0, 1, 2, 3, 4, 5};

    if (data)
    {
        *data = 5;
        elem = node_create(data);

        if (elem)
        {
            head = list_nums_fill(arr, 5);

            if (head)
            {
                sorted_insert(&head, elem, compare_int);

                for (node_t *cur = head; cur; cur = cur->next, i++)
                    ck_assert_int_eq(*(int*)cur->data, res[i]);

                ck_assert_int_eq(6, i);

                for (node_t *cur = head; cur; cur = cur->next)
                    free(cur->data);

                list_free_all(head);
            }
            else
            {
                free(elem);
                free(data);
            }
        }
        else
            free(data);
    }
}
END_TEST

START_TEST(test_sorted_insert_usual)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 11, 22, 33, 44}, i = 0;
    int res[6] = {0, 9, 11, 22, 33, 44};

    if (data)
    {
        *data = 9;
        elem = node_create(data);

        if (elem)
        {
            head = list_nums_fill(arr, 5);

            if (head)
            {
                sorted_insert(&head, elem, compare_int);

                for (node_t *cur = head; cur; cur = cur->next, i++)
                    ck_assert_int_eq(*(int*)cur->data, res[i]);

                ck_assert_int_eq(6, i);

                for (node_t *cur = head; cur; cur = cur->next)
                    free(cur->data);

                list_free_all(head);
            }
            else
            {
                free(elem);
                free(data);
            }
        }
        else
            free(data);
    }
}
END_TEST

Suite* sorted_insert_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sorted_insert");

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_sorted_insert_empty_list);
    tcase_add_test(tc_pos, test_sorted_insert_to_start);
    tcase_add_test(tc_pos, test_sorted_insert_to_end);
    tcase_add_test(tc_pos, test_sorted_insert_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
