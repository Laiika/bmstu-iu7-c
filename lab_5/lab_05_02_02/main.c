#include "funcs.h"

#define ARGS_NUMBER 2

int main(int argc, char **argv)
{
    int rc = OK;
    FILE *file = NULL;
    double average = 0.0, dispersion = 0.0;

    if (ARGS_NUMBER != argc)
        rc = ARGC_ERROR;
    else if (NULL == (file = fopen(argv[1], "r")))
        rc = FILE_ERROR;
    else if (OK == (rc = get_average(file, &average))) 
    {
        if (OK == (rc = calc_dispersion(file, &dispersion, average)))
            printf("%lf\n", dispersion);
    }

    if (OK != rc)
        print_error(rc);

    if (NULL != file)
        fclose(file);
        
    return rc;
}
