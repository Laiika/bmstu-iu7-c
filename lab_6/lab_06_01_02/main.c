#include "funcs.h"
#include <string.h>
#include <stdlib.h>

#define ARGC_ERROR -1
#define FILE_ERROR -2
#define WITHOUT_PREFIX 2
#define WITH_PREFIX 3

// argv[1] - имя файла, argv[2] - подстрока
int main(int argc, char **argv)
{
    FILE *file = NULL;

    if (WITH_PREFIX != argc && WITHOUT_PREFIX != argc)
        return ARGC_ERROR;

    if (!(NULL != (file = fopen(argv[1], "r")) || NULL != (file = fopen(strcat(argv[1], ".txt"), "r"))))
        return FILE_ERROR;

    struct item arr[ARRAY_MAX_SIZE];
    int rc;
    size_t size;

    if (EXIT_SUCCESS == (rc = read_items(file, arr, &size)))
    {
        if (WITHOUT_PREFIX == argc)
        {
            sort_items_array(arr, size);
            print_items_array(arr, size);
        }
        else if ((3 == strlen(argv[2])) && !strncmp("ALL", argv[2], 3))
            print_items_array(arr, size);
        else
            print_items_with_prefix(arr, size, argv[2]);
    }

    fclose(file);  
    return rc;
}
