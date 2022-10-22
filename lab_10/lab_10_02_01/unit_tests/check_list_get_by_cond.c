#include "check_list_get_by_cond.h"
#include "list_node.h"
#include "list.h"

START_TEST(test_list_get_by_cond_empty_list)
{
    monomial_t *head = NULL;

    ck_assert_ptr_eq(list_get_by_cond(head, monom_check_odd), NULL);
}
END_TEST

START_TEST(test_list_get_by_cond_empty_result)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 0}};
    monomial_t *head = list_fill(mtr, 3);

    if (head)
    {
        ck_assert_ptr_eq(list_get_by_cond(head, monom_check_odd), NULL);
        list_free_all(head);
    }
}
END_TEST

START_TEST(test_list_get_by_cond_usual)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}}, j = 0;
    int res[1][2] = {{1, 1}};
    monomial_t *head = list_fill(mtr, 3), *new_head = NULL;

    if (head)
    {
        new_head = list_get_by_cond(head, monom_check_odd);
        
        if (new_head)
        {
            for (monomial_t *cur = new_head; cur; cur = cur->next, j++)
            {
                ck_assert_int_eq(cur->coef, res[j][0]);
                ck_assert_int_eq(cur->deg, res[j][1]);
            }

            ck_assert_int_eq(j, 1);
            list_free_all(new_head);
        }

        list_free_all(head);
    }
}
END_TEST

Suite* list_get_by_cond_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("list_get_by_cond");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_list_get_by_cond_empty_list);
    tcase_add_test(tc_neg, test_list_get_by_cond_empty_result);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_list_get_by_cond_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
