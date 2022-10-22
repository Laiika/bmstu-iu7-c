#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "item.h"
#include "items.h"

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

    item_t *arr = NULL;
    int rc;
    size_t size;
    // получилось создать массив предметов из файла
    if (EXIT_SUCCESS == (rc = create_items_array(file, &arr, &size)))
    {
        if (WITHOUT_PREFIX == argc)
        {
            if (EXIT_SUCCESS == (rc = sort_items_array(arr, size)))
                print_items_array(arr, size);
        }
        else if ((3 == strlen(argv[2])) && !strncmp("ALL", argv[2], 3))
            print_items_array(arr, size);
        else
            print_items_with_prefix(arr, size, argv[2]);

        free_items_array(arr, size);
    }

    fclose(file);  
    return rc;
}
