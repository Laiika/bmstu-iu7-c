#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include "list_node.h"
#include "errors.h"

monomial_t *list_add_end(monomial_t *head, monomial_t *monom);
int list_read(monomial_t **head);
monomial_t *list_fill(int (*mtr)[2], const size_t elems);
void list_free_all(monomial_t *head);
void list_print(monomial_t *head);
int list_calc_polyn(monomial_t *head, const int val);
monomial_t *list_calc_dx(monomial_t *head);
monomial_t *lists_calc_sum(monomial_t *head1, monomial_t *head2);
monomial_t *list_get_by_cond(monomial_t *head, int (*compar)(monomial_t*));

#endif
