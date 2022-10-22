#include "element.h"

// функция для сравнения двух элементов
int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    
    return *a - *b;
}

// функция для обмена двух элементов
void swap_elements(void *p, void *q, size_t size)
{
    char temp;
    char *a = p;
    char *b = q;

    while (size)
    {
        temp = *a;
        *a++ = *b;
        *b++ = temp;
        size--;
    }
}
