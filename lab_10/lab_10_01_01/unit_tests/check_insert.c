#include <stdlib.h>
#include "check_insert.h"
#include "node.h"
#include "list.h"

START_TEST(test_insert_bad_before)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4}, i = 0;

    if (data)
    {
        *data = 5;
        elem = node_create(data);

        if (elem)
        {
            head = list_nums_fill(arr, 5);

            if (head)
            {
                insert(&head, elem, elem);

                for (node_t *cur = head; cur; cur = cur->next, i++)
                    ck_assert_int_eq(*(int*)cur->data, arr[i]);

                ck_assert_int_eq(5, i);

                for (node_t *cur = head; cur; cur = cur->next)
                    free(cur->data);

                list_free_all(head);
            }

            free(elem);
        }

        free(data);
    }
}
END_TEST

START_TEST(test_insert_empty_list)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));

    if (data)
    {
        *data = 5;
        elem = node_create(data);

        if (elem)
        {
            insert(&head, elem, head);
            ck_assert_ptr_eq(head, elem);
            ck_assert_ptr_eq(head->next, NULL);
            free(elem);
        }

        free(data);
    }
}
END_TEST

START_TEST(test_insert_to_start)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4}, i = 0;
    int res[6] = {5, 0, 1, 2, 3, 4};

    if (data)
    {
        *data = 5;
        elem = node_create(data);

        if (elem)
        {
            head = list_nums_fill(arr, 5);

            if (head)
            {
                insert(&head, elem, head);

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

START_TEST(test_insert_to_end)
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
                insert(&head, elem, NULL);

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

START_TEST(test_insert_usual)
{
    node_t *head = NULL, *elem = NULL;
    int *data = malloc(sizeof(int));
    int arr[5] = {0, 1, 2, 3, 4}, i = 0;
    int res[6] = {0, 5, 1, 2, 3, 4};

    if (data)
    {
        *data = 5;
        elem = node_create(data);

        if (elem)
        {
            head = list_nums_fill(arr, 5);

            if (head)
            {
                insert(&head, elem, head->next);

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

Suite* insert_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("insert");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_insert_bad_before);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_insert_empty_list);
    tcase_add_test(tc_pos, test_insert_to_start);
    tcase_add_test(tc_pos, test_insert_to_end);
    tcase_add_test(tc_pos, test_insert_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
