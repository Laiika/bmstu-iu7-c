#include "funcs.h"

/* Работаю с целыми числами типа int
* Для сортировки чисел использую сортировку выбором
* Числа сортируются по возрастанию
*/

int main(int argc, char **argv)
{
    if (NULL == argv || argc < 3 || NULL == argv[1])
        return ARGS_ERROR;

    int rc = OK;

    if ('c' == argv[1][0] && '\0' == argv[1][1])
        rc = fill_file(argv[argc - 1]);
    else if ('p' == argv[1][0] && '\0' == argv[1][1])
        rc = print_nums(argv[argc - 1]);
    else if ('s' == argv[1][0] && '\0' == argv[1][1])
        rc = sort_nums(argv[argc - 1]);
    else
        rc = ARGS_ERROR;

    return rc;
}
