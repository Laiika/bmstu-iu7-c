#include <stdio.h>
#include <string.h>
#include "my_strchr.h"

#define OK 0

int main()
{
    printf("%d\n", strchr("this is test.", 'i') == my_strchr("this is test.", 'i'));
    printf("%d\n", strchr("this is test.", '7') == my_strchr("this is test.", '7'));
    printf("%d\n", strchr("this is test.", '\0') == my_strchr("this is test.", '\0'));
    printf("%d\n", strchr("a", 'a') == my_strchr("a", 'a'));
    printf("%d\n", strchr("this is test.", 'e') == my_strchr("this is test.", 'e'));

    return OK;
}
