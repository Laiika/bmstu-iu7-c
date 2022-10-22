#include "check_lists_calc_sum.h"
#include "list_node.h"
#include "list.h"

START_TEST(test_lists_calc_sum_empty_lists)
{
    monomial_t *head = NULL, *head2 = NULL;
    
    ck_assert_ptr_eq(lists_calc_sum(head, head2), NULL);
}
END_TEST

START_TEST(test_lists_calc_sum_empty_sum)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}};
    int mtr2[3][2] = {{-3, 4}, {-22, 2}, {-1, 1}};
    monomial_t *head = list_fill(mtr, 3);

    if (head)
    {
        monomial_t *head2 = list_fill(mtr2, 3);

        if (head2)
        {
            ck_assert_ptr_eq(lists_calc_sum(head, head2), NULL);
            list_free_all(head2);
        }

        list_free_all(head);
    }
}
END_TEST

START_TEST(test_lists_calc_sum_empty_first_list)
{
    monomial_t *head = NULL, *sum = NULL;
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}}, j = 0;
    monomial_t *head2 = list_fill(mtr, 3);

    if (head2)
    {
        sum = lists_calc_sum(head, head2);

        if (sum)
        {
            for (monomial_t *cur = sum; cur; cur = cur->next, j++)
            {
                ck_assert_int_eq(cur->coef, mtr[j][0]);
                ck_assert_int_eq(cur->deg, mtr[j][1]);
            }

            ck_assert_int_eq(j, 3);
            list_free_all(sum);
        }

        list_free_all(head2);
    }
}
END_TEST

START_TEST(test_lists_calc_sum_empty_second_list)
{
    monomial_t *head2 = NULL, *sum = NULL;
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}}, j = 0;
    monomial_t *head = list_fill(mtr, 3);

    if (head)
    {
        sum = lists_calc_sum(head, head2);

        if (sum)
        {
            for (monomial_t *cur = sum; cur; cur = cur->next, j++)
            {
                ck_assert_int_eq(cur->coef, mtr[j][0]);
                ck_assert_int_eq(cur->deg, mtr[j][1]);
            }

            ck_assert_int_eq(j, 3);
            list_free_all(sum);
        }

        list_free_all(head);
    }
}
END_TEST

START_TEST(test_lists_calc_sum_usual)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}}, j = 0;
    int mtr2[4][2] = {{44, 8}, {3, 5}, {5, 4}, {-22, 2}};
    int res[4][2] = {{44, 8}, {3, 5}, {8, 4}, {1, 1}};
    monomial_t *head = list_fill(mtr, 3), *sum = NULL;

    if (head)
    {
        monomial_t *head2 = list_fill(mtr2, 4);

        if (head2)
        {
            sum = lists_calc_sum(head, head2);

            if (sum)
            {
                for (monomial_t *cur = sum; cur; cur = cur->next, j++)
                {
                    ck_assert_int_eq(cur->coef, res[j][0]);
                    ck_assert_int_eq(cur->deg, res[j][1]);
                }

                ck_assert_int_eq(j, 4);
                list_free_all(sum);
            }

            list_free_all(head2);
        }

        list_free_all(head);
    }
}
END_TEST

Suite* lists_calc_sum_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("lists_calc_sum");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_lists_calc_sum_empty_lists);
    tcase_add_test(tc_neg, test_lists_calc_sum_empty_sum);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_lists_calc_sum_empty_first_list);
    tcase_add_test(tc_pos, test_lists_calc_sum_empty_second_list);
    tcase_add_test(tc_pos, test_lists_calc_sum_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
