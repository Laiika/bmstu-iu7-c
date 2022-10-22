#include "funcs.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define EPS 1e-8

// функция для чтения названия предмета из файла
int read_name(FILE *file, char *const str, const size_t size)
{
    if (!fgets(str, size, file)) 
        return READ_ERROR;
        
    char ch;
    size_t len = strlen(str);

    if (NAME_LEN == len && (1 != fscanf(file, "%c", &ch) || '\n' != ch))
        return READ_ERROR;

    if ('\n' == str[len - 1])
        str[len - 1] = '\0';

    len = strlen(str);

    for (size_t i = 0; i < len; i++)
        if (' ' != str[i])
            return EXIT_SUCCESS;

    return READ_ERROR;
}

// функция для считывания одного предмета из файла
int read_item(FILE *file, struct item *cur)
{
    if (EXIT_SUCCESS != read_name(file, cur->name, sizeof(cur->name)))
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

// функция для считывания предметов из файла в массив
int read_items(FILE *file, struct item *const arr, size_t *const size)
{
    *size = 0;
    struct item cur;
    int rc;

    while ((*size) < ARRAY_MAX_SIZE && EXIT_SUCCESS == (rc = read_item(file, &cur)))
    {
        arr[*size] = cur;
        (*size)++;
    }

    if (EOF == rc)
    {
        arr[*size] = cur;
        (*size)++;
        rc = EXIT_SUCCESS;
    }
    else if (ARRAY_MAX_SIZE == (*size))
        rc = READ_ERROR;

    if (0 == (*size))
        rc = EMPTY_FILE;

    return rc;
}
