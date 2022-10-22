#include <stdio.h>
#include "get_ip.h"

int skip_spaces(char *const str, int i)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    return i;
}

int is_ip(char *const new_str, char *const str, int i)
{
    int j = 0;
    
    if (str[i] == '\0')
        return NOT_IP;

    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
        new_str[j++] = str[i++];

    new_str[j] = '\0';

    if (str[i] == '\0')
        return IP;

    i = skip_spaces(str, i);

    if (str[i] != '\0')
        return NOT_IP;

    return IP;
}

int get_ip(char *const new_str, char *const str)
{
    int i = 0;

    i = skip_spaces(str, i);

    return is_ip(new_str, str, i);
}
