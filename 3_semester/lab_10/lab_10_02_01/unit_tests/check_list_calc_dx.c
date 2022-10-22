#include "check_list_calc_dx.h"
#include "list_node.h"
#include "list.h"

START_TEST(test_list_calc_dx_empty_list)
{
    monomial_t *head = NULL;

    ck_assert_ptr_eq(list_calc_dx(head), NULL);
}
END_TEST

START_TEST(test_list_calc_dx_deg_is_0)
{
    monomial_t *head = NULL;
    monomial_t *monom = monom_create(1, 0);
    
    if (monom)
    {
        head = list_add_end(head, monom);
        ck_assert_ptr_eq(list_calc_dx(head), NULL);
        list_free_all(head);
    }
}
END_TEST

START_TEST(test_list_calc_dx_usual)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}}, j = 0;
    int res[3][2] = {{12, 3}, {44, 1}, {1, 0}};
    monomial_t *head = list_fill(mtr, 3), *dx = NULL;

    if (head)
    {
        dx = list_calc_dx(head);
        
        if (dx)
        {
            for (monomial_t *cur = dx; cur; cur = cur->next, j++)
            {
                ck_assert_int_eq(cur->coef, res[j][0]);
                ck_assert_int_eq(cur->deg, res[j][1]);
            }

            ck_assert_int_eq(j, 3);
            list_free_all(dx);
        }

        list_free_all(head);
    }
}
END_TEST

Suite* list_calc_dx_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("list_calc_dx");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_list_calc_dx_empty_list);
    tcase_add_test(tc_neg, test_list_calc_dx_deg_is_0);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_list_calc_dx_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
