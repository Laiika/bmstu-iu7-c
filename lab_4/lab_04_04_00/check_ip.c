#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check_ip.h"
#include "get_pos_number.h"

int check_byte(char *const str)
{
    if (strlen(str) > BYTE_LEN)
        return FALSE;
    
    int number = get_pos_number(str);

    if (number == FALSE)
        return FALSE;

    if (number <= MAX_BYTE && number >= MIN_BYTE)
        return TRUE;

    return FALSE;
}

int check_bytes(char *const str)
{
    int j = 0;
    char *byte = str, *end = strchr(str, '.');

    while (j < (BYTES_NUM - 1))
    {  
        if (end == NULL)
            return NO;

        *end = '\0';

        if ((strlen(byte) == 0) || (check_byte(byte) == FALSE))
            return NO;

        j++;
        byte = end + 1;
        end = strchr(byte, '.');
    }

    if (end || (strlen(byte) == 0) || (check_byte(byte) == FALSE))
        return NO;

    return YES;
}

int check_ip(char *const str)
{
    if (str == NULL)
        return STRING_INPUT_ERROR;
    
    return check_bytes(str);
}
