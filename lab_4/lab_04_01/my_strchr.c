#include <stdio.h>
#include "my_strchr.h"

char *my_strchr(const char *const str, const int ch)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == ch)
            return (char*)(str + i);

    if (ch == '\0')
        return (char*)(str + i);
    
    return NULL;
}
