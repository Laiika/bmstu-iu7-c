#include <stdlib.h>
#include "check_copy.h"
#include "node.h"
#include "list.h"
#include "errors.h"

START_TEST(test_copy_empty_list)
{
    node_t *head = NULL, *head2 = NULL;
    int rc = copy(head, &head2);

    ck_assert_int_eq(rc, EMPTY_LIST);
    ck_assert_ptr_eq(head2, NULL);

}
END_TEST

START_TEST(test_copy_usual)
{
    node_t *head = NULL, *head2 = NULL;
    int arr[5] = {0, 1, 2, 4, 5}, rc;

    head = list_nums_fill(arr, 5);

    if (head)
    {
        rc = copy(head, &head2);

        if (MEMORY_ERROR != rc)
        {
            ck_assert_int_eq(rc, EXIT_SUCCESS);

            for (node_t *cur = head, *cur2 = head2; cur && cur2; cur = cur->next, cur2 = cur2->next)
                ck_assert_ptr_eq(cur->data, cur2->data);

            list_free_all(head2);
        }

        for (node_t *cur = head; cur; cur = cur->next)
            free(cur->data);

        list_free_all(head);
    }
}
END_TEST

Suite* copy_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("copy");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_copy_empty_list);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_copy_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
