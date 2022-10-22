#include <string.h>
#include "funcs.h"

#define TRUE 1
#define FALSE 0
#define FOUND 1
#define NOT_FOUND 0
#define NO_NEEDED_ENTRY -2

int check_name(struct product prod, char *const substr)
{
    int len = strlen(substr), len2 = strlen(prod.name);

    if ((len2 >= len) && !strncmp(&(prod.name[len2 - len]), substr, len))
        return TRUE;
    
    return FALSE;
}

int check_product(FILE *file, char *const substr, size_t size)
{
    if (NULL == file)
        return FILE_ERROR;

    int flag = NOT_FOUND;
    struct product cur;
    memset(&cur, 0, sizeof(struct product));
    size_t count = size / sizeof(struct product);

    for (size_t i = 0; i < count; i++)
    {
        if (!fread(&cur, sizeof(struct product), 1, file))
            return FILE_ERROR;

        if (TRUE != check_name(cur, substr))
            continue;
    
        flag = FOUND;
        print_entry(stdout, cur);
    }

    if (!flag)
        return NO_NEEDED_ENTRY;

    return OK;
}

int print_spec_products(char *const f, char *const substr)
{
    FILE *file = fopen(f, "rb");
    size_t size;

    if ((NULL == file) || (NULL == substr) || (0 == strlen(substr)))
        return FILE_ERROR;

    if ((OK != file_size(file, &size)) || (0 != size % sizeof(struct product)))
    {
        fclose(file);
        return FILE_ERROR;
    }

    int rc = check_product(file, substr, size);

    fclose(file);
    return rc;
}
