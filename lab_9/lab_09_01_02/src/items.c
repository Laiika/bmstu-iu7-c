#include <string.h>
#include "items.h"

#define YES 0
#define NO 1

// функция для освобождения памяти из под массива предметов
void free_items_array(item_t *arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        free_item(arr + i);

    free(arr);
}

// функция для подсчета числа предметов в файле
int count_items(FILE *file, size_t *const size)
{
    *size = 0;
    item_t cur;
    cur.name = NULL;
    int rc;
    // чтение очередного предмета
    while (EXIT_SUCCESS == (rc = read_item(file, &cur)))
    {
        (*size)++;
        free_item(&cur);
    }

    if (EOF == rc)
    {
        (*size)++;
        rc = EXIT_SUCCESS;
    }

    if (0 == (*size))
        rc = EMPTY_FILE;

    free_item(&cur);
    return rc;
}

// функция для считывания предметов из файла в массив
int read_items_array(FILE *file, item_t *const arr, const size_t size)
{
    int rc = EXIT_SUCCESS;
    size_t i;

    for (i = 0; EXIT_SUCCESS == rc && i < size; i++)
        rc = read_item(file, arr + i);

    if (EOF == rc && i == size)
        rc = EXIT_SUCCESS;

    return rc;
}

// функция для создания массива предметов из файла
int create_items_array(FILE *file, item_t **arr, size_t *const size)
{
    int rc = EXIT_SUCCESS;

    *arr = NULL;
    // подсчет числа предметов в файле
    if (EXIT_SUCCESS != (rc = count_items(file, size)))
        return rc;

    *arr = calloc(*size, sizeof(item_t));
    // проверка успешности выделения
    if (NULL != (*arr))
    {
        rewind(file);
        // чтение предметов из файла в массив
        if (EXIT_SUCCESS != (rc = read_items_array(file, *arr, *size)))
            free_items_array(*arr, *size);
    }
    else
        rc = MEMORY_ERROR;

    return rc;
}

// функция для сортировки предметов в массиве по возрастанию плотности
int sort_items_array(item_t *const arr, const size_t size)
{
    int rc = EXIT_SUCCESS;

    for (size_t i = 1; i < size; i++)
    {
        int j = i - 1;

        while (j >= 0 && cmp_items_by_ro(arr + j, arr + j + 1) > 0)
        {
            if (EXIT_SUCCESS != (rc = swap_items(arr + j, arr + j + 1)))
                return rc;

            j--;
        }
    }

    return rc;
}

// функция для печати массива предметов
void print_items_array(const item_t *const arr, const size_t size)
{
    for (size_t i = 0; i < size; i++)
        print_item(arr + i);
}

// функция для проверки что строка начинается с переданной подстроки
int check_prefix(const char *const str, const char *const prefix)
{
    size_t len = strlen(prefix);

    if (strlen(str) < len)
        return NO;

    for (size_t i = 0; i < len; i++)
        if (str[i] != prefix[i])
            return NO;

    return YES;
}

// функция для печати предметов, названия которых начинаются с переданной подстоки
void print_items_with_prefix(const item_t *const arr, const size_t size, const char *const prefix)
{
    for (size_t i = 0; i < size; i++)
        if (YES == check_prefix(arr[i].name, prefix))
            print_item(arr + i);
}
