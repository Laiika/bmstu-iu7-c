#include "funcs.h"
#include <string.h>

#define YES 0
#define NO 1

// функция для проверки что строка начинается с переданной подстроки
int check_prefix(char *const str, char *const prefix)
{
    size_t len = strlen(prefix);

    if (strlen(str) < len)
        return NO;

    for (size_t i = 0; i < len; i++)
        if (str[i] != prefix[i])
            return NO;

    return YES;
}

// функция для печати предметов, названия которых начинаются с переданной подстоки
void print_items_with_prefix(struct item *const arr, const size_t size, char *const prefix)
{
    for (size_t i = 0; i < size; i++)
        if (YES == check_prefix(arr[i].name, prefix))
        {
            printf("%s\n", arr[i].name);
            printf("%f\n", arr[i].weight);
            printf("%f\n", arr[i].volume);
        }
}
