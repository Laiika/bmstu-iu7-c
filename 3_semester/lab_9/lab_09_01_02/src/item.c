#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "item.h"

#define EPS 1e-8

// функция для копирования предмета
int copy_item(const item_t *const from, item_t *const to)
{
    char *temp = strdup(from->name);

    if (temp)
    {
        free(to->name);
        to->name = temp;
        to->volume = from->volume;
        to->weight = from->weight;

        return EXIT_SUCCESS;
    }

    return MEMORY_ERROR;
}

// функция для освобождения памяти из под предмета
void free_item(item_t *cur)
{
    free(cur->name);
    cur->name = NULL;
}

// функция для чтения названия предмета из файла
int read_name(FILE *file, char **str)
{
    size_t size = 0;
    ssize_t len;
    *str = NULL;
    // попытка считать строку
    if (-1 == (len = getline(str, &size, file)))
    {
        free(*str);
        *str = NULL;
        return READ_ERROR;
    }

    if (len)
    {
        for (size_t i = 0; i < (len - 1); i++)
            if (' ' != (*str)[i])
                return EXIT_SUCCESS;
    }

    free(*str);
    *str = NULL;
    return READ_ERROR;
}

// функция для считывания одного предмета из файла
int read_item(FILE *file, item_t *const cur)
{
    if (EXIT_SUCCESS != read_name(file, &(cur->name)))
        return READ_ERROR;

    if (1 != fscanf(file, "%f", &(cur->weight)) || cur->weight < 0 || fabs(cur->weight) < EPS)
        return READ_ERROR;

    if (1 != fscanf(file, "%f", &(cur->volume)) || cur->volume < 0 || fabs(cur->volume) < EPS)
        return READ_ERROR;

    char ch;
    
    if (1 != fscanf(file, "%c", &ch))
    {
        if (feof(file))
            return EOF;

        return READ_ERROR;
    }
    else if ('\n' != ch)
        return READ_ERROR;

    return EXIT_SUCCESS;
}

// функция для печати полей предмета на экран
void print_item(const item_t *const cur)
{
    printf("%s", cur->name);
    printf("%f\n", cur->weight);
    printf("%f\n", cur->volume);
}

// функция для сравнения двух предметов по плотности
int cmp_items_by_ro(const item_t *const f, const item_t *const s)
{
    float ro1 = f->weight / f->volume;
    float ro2 = s->weight / s->volume;
    return ro1 - ro2;
}

// функция, меняющая местами два предмета
int swap_items(item_t *const f, item_t *const s)
{
    item_t temp;
    temp.name = NULL;
    int rc = EXIT_SUCCESS;

    if (EXIT_SUCCESS == (rc = copy_item(f, &temp)))
    {
        if (EXIT_SUCCESS == (rc = copy_item(s, f)))
            rc = copy_item(&temp, s);
        
        free_item(&temp);
    }
    
    return rc;
}
