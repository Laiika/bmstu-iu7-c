#include <stdio.h>
#include <stdlib.h>
#include "../inc/list_node.h"

// функция для создания элемента списка
monomial_t *monom_create(const int coef, const int deg)
{
    monomial_t *monom = malloc(sizeof(monomial_t));

    if (monom)
    {
        monom->coef = coef;
        monom->deg = deg;
        monom->next = NULL;        
    }
        
    return monom;
}

// функция для освобождения памяти из под элемента списка
void monom_free(monomial_t *monom)
{
    free(monom);
}

// функция для печати данных элемента списка
void monom_print(monomial_t *monom)
{
    printf("%d %d ", monom->coef, monom->deg);
}

// функция для вычисления значения одночлена
int monom_calc(monomial_t *monom, int val)
{
    int res = monom->coef;

    for (int i = 0; i < monom->deg; i++)
        res *= val;

    return res;
}

// функция для проверки на нечетность
int monom_check_odd(monomial_t *monom)
{
    if (0 != monom->deg % 2)
        return 0;
    
    return 1;
}

// функция для проверки на четность
int monom_check_even(monomial_t *monom)
{
    return monom->deg % 2;
}
