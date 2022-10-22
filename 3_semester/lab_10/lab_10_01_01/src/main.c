#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errors.h"
#include "node.h"
#include "list.h"

int main(int argc, char **argv)
{
    FILE *in = NULL, *out = NULL;
    int rc = EXIT_SUCCESS;
    node_t *head;

    if (NULL == (in = fopen(argv[1], "r")))
        return FILE_ERROR;

    if (NULL == (out = fopen(argv[2], "w")))
    {
        fclose(in);
        return FILE_ERROR;
    }
    // создание списка чисел
    if (EXIT_SUCCESS == (rc = list_nums_read(in, &head)))
    {
        // проверка наличия числа в списке с помощью find
        if (5 == argc && 4 == strlen(argv[3]) && !strncmp(argv[3], "find", 4))
        {
            int *data = malloc(sizeof(int));

            if (data)
            {
                *data = atoi(argv[4]);
                node_t *elem = find(head, data, compare_int);

                if (elem)
                    fprintf(out, "found\n");
                else
                    fprintf(out, "not found\n");

                free(data); 
            }
            else
                rc = MEMORY_ERROR;
        }
        // сортировка списка
        else if (4 == argc && 4 == strlen(argv[3]) && !strncmp(argv[3], "sort", 4))
        {
            head = sort(head, compare_int);    
            list_nums_print(out, head);
        }
        // добавление числа в начало списка
        else if (5 == argc && 6 == strlen(argv[3]) && !strncmp(argv[3], "insert", 6))
        {
            int *data = malloc(sizeof(int));

            if (data)
            {
                *data = atoi(argv[4]);
                
                node_t *new_head, *elem = node_create(data);

                if (elem && EXIT_SUCCESS == (rc = copy(head, &new_head)))
                {
                    insert(&new_head, elem, new_head);
                    list_nums_print(out, head);
                    list_nums_print(out, new_head);

                    list_free_all(new_head);
                }
                else if (!elem)
                    rc = MEMORY_ERROR;
                else   
                    free(elem);

                free(data); 
            }
            else
                rc = MEMORY_ERROR;
        }
        else
            rc = INPUT_ERROR;

        // освобождение памяти из под данных
        for (node_t *cur = head; cur; cur = cur->next)
            free(cur->data);
        // освобождение памяти из под элементов списка
        list_free_all(head);
    }

    fclose(in);
    fclose(out);
    return rc;
}
