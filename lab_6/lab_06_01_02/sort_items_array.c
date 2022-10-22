#include "funcs.h"

// функция, меняющая местами в массиве два предмета с указанными индексами 
void swap_items(struct item *const arr, const size_t i, const size_t j)
{
    struct item temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// функция для сортировки предметов в массиве по возрастанию плотности
void sort_items_array(struct item *const arr, const size_t size)
{
    for (size_t i = 1; i < size; i++)
    {
        int j = i - 1;
        float ro_j = arr[j].weight / arr[j].volume;
        float ro_j1 = arr[j + 1].weight / arr[j + 1].volume;

        while (j >= 0 && ro_j > ro_j1)
        {
            swap_items(arr, j, j + 1);
            j--;
            ro_j = arr[j].weight / arr[j].volume;
            ro_j1 = arr[j + 1].weight / arr[j + 1].volume;
        }
    }
}
