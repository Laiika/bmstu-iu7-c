#include "funcs.h"

int calc_dispersion(FILE *const f, double *const dispersion, const double average)
{
    if (NULL == f)
        return FILE_ERROR;

    if (NULL == dispersion)
        return PARAM_ERROR;

    double sum = 0.0, number;
    int count = 0;

    while (1 == fscanf(f, "%le", &number))
    {
        sum += (number - average) * (number - average);
        count++;
    }

    *dispersion = sum / count;

    return OK;
}
