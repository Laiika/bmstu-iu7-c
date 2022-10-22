#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
#include "list_node.h"
#include "errors.h"

#define COMMAND_LEN 3

int main(void)
{
    char str[COMMAND_LEN + 1];
    int rc = EXIT_SUCCESS;
    // считывание команды
    if (!fgets(str, sizeof(str), stdin) || (strlen(str) != COMMAND_LEN) || (getchar() != '\n'))
        return INPUT_ERROR;

    // вычисение полинома
    if (0 == strncmp(str, "val", COMMAND_LEN))
    {
        monomial_t *head = NULL;
        // создание списка
        if (EXIT_SUCCESS == (rc = list_read(&head)) && NULL != head)
        {
            int val;
            // считывание значения переменной х
            if (1 == scanf("%d", &val))
                printf("%d\n", list_calc_polyn(head, val));
            else
                rc = INPUT_ERROR;
        }
        else if (NULL == head)
            rc = EMPTY_LIST;

        list_free_all(head);
    }
    // вычисление производной
    else if (0 == strncmp(str, "ddx", COMMAND_LEN))
    {
        monomial_t *head = NULL, *new_head;
        // создание списка
        if (EXIT_SUCCESS == (rc = list_read(&head)) && NULL != head)
        {
            // производная = 0
            if (0 == head->deg)
                rc = EMPTY_LIST;
            // вычисление производной
            else if (NULL != (new_head = list_calc_dx(head)))
            {
                list_print(new_head);
                list_free_all(new_head);
            }
            else
                rc = MEMORY_ERROR;
        }
        else if (NULL == head)
            rc = EMPTY_LIST;

        list_free_all(head);
    }
    // сложение двух полиномов
    else if (0 == strncmp(str, "sum", COMMAND_LEN))
    {
        monomial_t *head1 = NULL, *head2 = NULL, *new_head;
        // создание списка
        if (EXIT_SUCCESS == (rc = list_read(&head1)) && NULL != head1)
        {
            if (EXIT_SUCCESS == (rc = list_read(&head2)) && NULL != head2)
            {
                // вычисление суммы списков
                if (NULL != (new_head = lists_calc_sum(head1, head2)))
                {
                    list_print(new_head);
                    list_free_all(new_head);
                }
                else
                    rc = MEMORY_ERROR;
            }
            else if (NULL == head2)
                rc = EMPTY_LIST;
        }
        else if (NULL == head1)
            rc = EMPTY_LIST;

        list_free_all(head1);
        list_free_all(head2);
    }
    // разделение полинома на полиномы четных и нечетных степеней
    else if (0 == strncmp(str, "dvd", COMMAND_LEN))
    {
        monomial_t *head = NULL, *new_head;
        // создание списка
        if (EXIT_SUCCESS == (rc = list_read(&head)) && NULL != head)
        {
            // получение четных степеней
            if (NULL != (new_head = list_get_by_cond(head, monom_check_even)))
            {
                list_print(new_head);
                list_free_all(new_head);
                new_head = NULL;

                // получение нечетных степеней
                if (NULL != (new_head = list_get_by_cond(head, monom_check_odd)))
                {
                    list_print(new_head);
                    list_free_all(new_head);
                }
                else
                    rc = MEMORY_ERROR;
            }
            else
                rc = MEMORY_ERROR;
        }
        else if (NULL == head)
            rc = EMPTY_LIST;

        list_free_all(head);
    }
    else
        return rc = INPUT_ERROR;

    return rc;
}
