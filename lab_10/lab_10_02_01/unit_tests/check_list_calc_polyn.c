#include "check_list_calc_polyn.h"
#include "list_node.h"
#include "list.h"

START_TEST(test_list_calc_polyn_empty_list)
{
    monomial_t *head = NULL;

    ck_assert_int_eq(list_calc_polyn(head, 7), 0);
}
END_TEST

START_TEST(test_list_calc_polyn_usual)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}};
    monomial_t *head = list_fill(mtr, 3);

    if (head)
    {
        ck_assert_int_eq(list_calc_polyn(head, 3), 444);
        list_free_all(head);
    }
}
END_TEST

Suite* list_calc_polyn_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("list_calc_polyn");
    
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_list_calc_polyn_empty_list);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_list_calc_polyn_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
