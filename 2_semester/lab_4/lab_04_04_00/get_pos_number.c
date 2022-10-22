#include <stdio.h>
#include "get_pos_number.h"

int get_pos_number(char *const str)
{
    if (str == NULL)
        return FALSE;

    int i = 0, number = 0;

    while (str[i] != '\0')
    {
        if (!('0' <= str[i] && str[i] <= '9'))
            return FALSE;

        number = number * 10 + (int)(str[i] - '0');
        i++;
    }

    return number;
}
