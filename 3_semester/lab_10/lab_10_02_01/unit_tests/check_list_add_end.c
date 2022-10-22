#include "check_list_add_end.h"
#include "list_node.h"
#include "list.h"

START_TEST(test_list_add_end_empty_list)
{
    monomial_t *head = NULL;
    monomial_t *monom = monom_create(1, 2);
    
    if (monom)
    {
        head = list_add_end(head, monom);
        ck_assert_ptr_eq(head, monom);
        list_free_all(head);
    }
}
END_TEST

START_TEST(test_list_add_end_usual)
{
    int mtr[3][2] = {{3, 4}, {22, 2}, {1, 1}}, j = 0;
    int res[4][2] = {{3, 4}, {22, 2}, {1, 1}, {1, 0}};
    monomial_t *head = list_fill(mtr, 3);

    if (head)
    {
        monomial_t *monom = monom_create(1, 0);

        if (monom)
        {
            head = list_add_end(head, monom);

            for (monomial_t *cur = head; cur; cur = cur->next, j++)
            {
                ck_assert_int_eq(cur->coef, res[j][0]);
                ck_assert_int_eq(cur->deg, res[j][1]);
            }

            ck_assert_int_eq(j, 4);
        }

        list_free_all(head);
    }
}
END_TEST

Suite* list_add_end_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("list_add_end");

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_list_add_end_empty_list);
    tcase_add_test(tc_pos, test_list_add_end_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
