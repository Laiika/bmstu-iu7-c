#include <stdio.h>
#include <string.h>
#include "read_string.h"

int read_string(char *const str, const int size)
{
    if (!fgets(str, size, stdin))
        return STRING_INPUT_ERROR;

    int ch, len = strlen(str);

    if ((len == STR_LEN) && ((ch = getchar()) != '\n' && ch != EOF))
        return STRING_INPUT_ERROR;

    if (str[0] == '\n')
        return STRING_INPUT_ERROR;

    if (str[len - 1] == '\n')
        str[len - 1] = '\0';

    return OK;
}
