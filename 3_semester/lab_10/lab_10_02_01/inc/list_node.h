#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

typedef struct monomial monomial_t;
// одночлен
struct monomial
{
    int coef; // коэффициент
    int deg; // степень
    
    monomial_t *next; // указатель на следующий
};

monomial_t *monom_create(const int coef, const int deg);
void monom_free(monomial_t *monom);
void monom_print(monomial_t *monom);
int monom_calc(monomial_t *monom, int val);
int monom_check_odd(monomial_t *monom);
int monom_check_even(monomial_t *monom);

#endif
