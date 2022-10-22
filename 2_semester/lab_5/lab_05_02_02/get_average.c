#include "funcs.h"

int calc_average(FILE *const f, double *const average, double number)
{
    if (NULL == f)
        return FILE_ERROR;

    if (NULL == average)
        return PARAM_ERROR;

    double sum = number;
    int count = 1;

    while (1 == fscanf(f, "%le", &number))
    {
        sum += number;
        count++;
    }

    *average = sum / count;

    return OK;
}

int get_average(FILE *const f, double *const average)
{
    if (NULL == f)
        return FILE_ERROR;

    if (NULL == average)
        return PARAM_ERROR;

    double number;

    if (1 != fscanf(f, "%le", &number))
        return feof(f) ? EMPTY_FILE : NO_NUMBERS;

    int rc;
    
    if (OK != (rc = calc_average(f, average, number)))
        return rc;

    if (!feof(f))
        return READ_ERROR;

    rewind(f);
    return OK;
}
