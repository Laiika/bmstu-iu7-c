#include <stdio.h>
#include <string.h>
#include "check_ip.h"
#include "get_ip.h"
#include "read_string.h"

int main()
{
    char str[STR_LEN + 1], new_str[STR_LEN + 1];

    if (read_string(str, sizeof(str)) != OK || str == NULL)
        return STRING_INPUT_ERROR;

    if (strlen(str) == 0 || get_ip(new_str, str) == NOT_IP)
    {
        printf("NO\n");
        return OK;
    }
    
    int result = check_ip(new_str);

    if (result == YES)
        printf("YES\n");
    else if (result == NO)
        printf("NO\n");
    else
        return STRING_INPUT_ERROR;

    return OK;
}
