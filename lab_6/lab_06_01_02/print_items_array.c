#include "funcs.h"

// функция для печати массива предметов
void print_items_array(struct item *const arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%s\n", arr[i].name);
        printf("%f\n", arr[i].weight);
        printf("%f\n", arr[i].volume);
    }
}
