#include "element.h"

// функция для сравнения двух элементов
int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    
    return *a - *b;
}
