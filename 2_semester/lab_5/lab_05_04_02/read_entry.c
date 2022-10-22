#include <string.h>
#include "funcs.h"

int read_string(char *const str, const int size, const int max_len)
{
    if (NULL == str)
        return INPUT_ERROR;

    if (!fgets(str, size, stdin))
        return INPUT_ERROR;

    int ch, len = strlen(str);

    if ((len == max_len) && ((ch = getchar()) != '\n'))
        return INPUT_ERROR;

    if ('\n' == str[0])
        return INPUT_ERROR;

    if ('\n' == str[len - 1])
        str[len - 1] = '\0';

    return OK;
}

int read_entry(struct product *prod)
{
    if (NULL == prod)
        return INPUT_ERROR;

    if (OK != read_string(prod->name, NAME_LEN + 1, NAME_LEN))
        return INPUT_ERROR;

    if (OK != read_string(prod->producer, PRODUCER_LEN + 1, PRODUCER_LEN))
        return INPUT_ERROR;

    if (1 != scanf("%u", &(prod->price)))
        return INPUT_ERROR;

    if (1 != scanf("%u", &(prod->amount)))
        return INPUT_ERROR;

    return OK;
}
