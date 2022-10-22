#include <stdlib.h>
#include "list.h"

// фукнция для добавления элемента в конец списка
monomial_t *list_add_end(monomial_t *head, monomial_t *monom)
{
    if (!head)
        return monom;

    monomial_t *cur = head;

    while (cur->next)
        cur = cur->next;

    cur->next = monom;

    return head;
}

// функция для считывания целого числа
int get_number(int *num, char *ch)
{
    int len = 0;
    char sign = '+';
    char str[20];
    *num = 0;

    while (1 == scanf("%c", ch) && '\n' != *ch && ' ' != *ch)
    {    
        // считана цифра
        if ('0' <= *ch && '9' >= *ch)
        {
            str[len] = *ch;
            len++;
        }
        else if (('+' == *ch || '-' == *ch) && 0 == len)
            sign = *ch;
        else 
            return INPUT_ERROR;
    }

    if (('\n' != *ch && ' ' != *ch) || 0 == len)
        return INPUT_ERROR;
    // преобразование в число
    str[len] = '\0';
    *num = atoi(str);

    if ('-' == sign)
        (*num) = (*num) * -1;

    return EXIT_SUCCESS;
}

// функция для создания списка с клавиатуры
int list_read(monomial_t **head)
{
    *head = NULL;
    monomial_t *node;
    int last_deg, coef, deg, rc;
    char ch = '0';
    
    while ('\n' != ch)
    {
        // считывание коэффициента одночлена
        if (EXIT_SUCCESS != (rc = get_number(&coef, &ch)) || '\n' == ch)
            return INPUT_ERROR;
        // считывание степени одночлена
        if (EXIT_SUCCESS != (rc = get_number(&deg, &ch)) || deg < 0 || (NULL != *head && last_deg <= deg))
            return INPUT_ERROR;

        if (0 != coef) 
        {
            // создание элемента списка
            node = monom_create(coef, deg);

            if (NULL == node)
                return MEMORY_ERROR;

            *head = list_add_end(*head, node);
            last_deg = deg;  
        }
    }

    return EXIT_SUCCESS;
}

// функция для заполнения списка из матрицы
monomial_t *list_fill(int (*mtr)[2], const size_t elems)
{
    monomial_t *monom = NULL, *head = NULL;
    
    for (size_t i = 0; i < elems; i++)
    {
        if (NULL == (monom = monom_create(mtr[i][0], mtr[i][1])))
        {
            list_free_all(head);
            return NULL;
        }

        head = list_add_end(head, monom);
    }

    return head;
}

// функция для освобождения памяти из под списка
void list_free_all(monomial_t *head)
{
    monomial_t *next;

    for (; head; head = next)
    {
        next = head->next;
        monom_free(head);
    }
}

// функция для печати элементов списка
void list_print(monomial_t *head)
{
    for (; head; head = head->next)
        monom_print(head);

    printf("L\n");
}

// функция для вычисления значения полинома
int list_calc_polyn(monomial_t *head, const int val)
{
    int p = 0;

    for (; head; head = head->next)
        p += monom_calc(head, val);

    return p;   
}

// функция для вычисления производной
monomial_t *list_calc_dx(monomial_t *head)
{
    monomial_t *new_head = NULL, *node;

    for (; head; head = head->next)
    {
        if (0 != head->deg)
        {
            node = monom_create(head->coef * head->deg, head->deg - 1);

            if (NULL == node)
            {
                list_free_all(new_head);
                return NULL;
            }

            new_head = list_add_end(new_head, node);
        }
    }
        
    return new_head;   
}

// функция для сложения двух списков
monomial_t *lists_calc_sum(monomial_t *head1, monomial_t *head2)
{
    monomial_t *new_head = NULL, *node;

    while (head1 && head2)
    {
        if (!(head1->deg == head2->deg && 0 == head1->coef + head2->coef))
        {
            if (head1->deg > head2->deg)
            {
                node = monom_create(head1->coef, head1->deg);
                head1 = head1->next;
            }
            else if (head1->deg < head2->deg)
            {
                node = monom_create(head2->coef, head2->deg);
                head2 = head2->next;
            }
            else
            {
                node = monom_create(head1->coef + head2->coef, head1->deg);
                head1 = head1->next;
                head2 = head2->next;
            }

            if (NULL == node)
            {
                list_free_all(new_head);
                return NULL;
            }

            new_head = list_add_end(new_head, node);
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    if (NULL != head2)
        head1 = head2;
    // добавление оставшихся в одном списке элементов
    while (head1)
    {
        node = monom_create(head1->coef, head1->deg);

        if (NULL == node)
        {
            list_free_all(new_head);
            return NULL;
        }

        new_head = list_add_end(new_head, node);
        head1 = head1->next;
    }
        
    return new_head;   
}

// функция для получения элементов из списка, удовлетворяющих условию
monomial_t *list_get_by_cond(monomial_t *head, int (*compar)(monomial_t*))
{
    monomial_t *new_head = NULL, *node;

    for (; head; head = head->next)
    {
        // условие выполнено
        if (0 == compar(head))
        {
            node = monom_create(head->coef, head->deg);

            if (NULL == node)
            {
                list_free_all(new_head);
                return NULL;
            }

            new_head = list_add_end(new_head, node);
        }
    }
        
    return new_head;   
}
