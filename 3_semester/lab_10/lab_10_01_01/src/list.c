#include "list.h"

#define FOUND 1
#define NOT_FOUND 0

// функция для добавления элемента в конец списка
node_t *list_add_end(node_t *head, node_t *elem)
{
    if (!head)
        return elem;

    node_t *cur = head;

    while (cur->next)
        cur = cur->next;

    cur->next = elem;

    return head;
}

// функция для освобождения памяти из под элементов списка
void list_free_all(node_t *head)
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}

// функция для поиска элемента в списке
node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*))
{
    for (; head; head = head->next)
    {
        if (0 == comparator(head->data, data))
            return head;
    }

    return NULL;
}

// функция для вставки элемента перед указанным элементом списка
void insert(node_t **head, node_t *elem, node_t *before)
{
    if (*head == before)
    {
        // вставка в начало списка
        elem->next = *head;
        *head = elem;
    }
    else
    {
        for (node_t *cur = *head; cur; cur = cur->next)
        {
            if (cur->next == before)
            {
                elem->next = cur->next;
                cur->next = elem;  
                break;
            }
        }
    }
}

// функция для создания копии списка
int copy(node_t *head, node_t **new_head)
{
    node_t *prev = NULL, *node;
    *new_head = NULL;

    if (!head)
        return EMPTY_LIST;

    for (; head; head = head->next)
    {
        node = malloc(sizeof(node_t));

        if (node)
        {
            node->data = head->data;
            node->next = NULL;   

            if (prev)
                prev->next = node;
            else
                *new_head = node;

            prev = node;     
        }
        else
        {
            list_free_all(*new_head);
            *new_head = NULL;
            return MEMORY_ERROR;
        }
    }

    return EXIT_SUCCESS;
}

// функция для вставки элемента в упорядоченный список
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*))
{
    node_t *last;
    int f = NOT_FOUND;
    element->next = NULL;

    if (NULL == *head)
    {
        *head = element;
        f = FOUND;
    }

    for (node_t *cur = *head; cur && (NOT_FOUND == f); cur = cur->next)
    {
        if (comparator(element->data, cur->data) <= 0)
        {
            // вставка перед текущим элементом
            insert(head, element, cur);
            f = FOUND;
        }

        last = cur;
    }

    if (NOT_FOUND == f)
        last->next = element;
}

// функция для сортировки списка
node_t *sort(node_t *head, int (*comparator)(const void*, const void*))
{
    node_t *new_head = NULL, *next;

    for (; head; head = next)
    {
        next = head->next;
        sorted_insert(&new_head, head, comparator);
    }
    
    return new_head;
}

// функция для создания списка целых чисел из файла
int list_nums_read(FILE *file, node_t **head)
{
    int num, *data;
    node_t *elem;
    *head = NULL;

    while (1 == fscanf(file, "%d", &num))
    {
        data = malloc(sizeof(int));

        if (data)
        {
            *data = num;
            elem = node_create(data);
            // добавление элемента в конец списка
            if (elem)
                *head = list_add_end(*head, elem);
            else
            {
                // освобождение памяти из под данных
                for (node_t *cur = *head; cur; cur = cur->next)
                    free(cur->data);

                free(data);
                list_free_all(*head);
                return MEMORY_ERROR;
            }
        }
        else
        {
            // освобождение памяти из под данных
            for (node_t *cur = *head; cur; cur = cur->next)
                free(cur->data);

            list_free_all(*head);
            return MEMORY_ERROR;
        }   
    }

    if (NULL == *head)
        return EMPTY_LIST;

    if (feof(file))
        return EXIT_SUCCESS;

    return INPUT_ERROR;
}

// функция для создания списка целых чисел из массива
node_t *list_nums_fill(int *arr, const size_t size)
{
    node_t *head = NULL, *elem = NULL;
    int *data = NULL;

    for (size_t i = 0; i < size; i++)
    {
        data = malloc(sizeof(int));

        if (data)
        {
            *data = arr[i];
            elem = node_create(data);
                
            if (elem)
                head = list_add_end(head, elem);
            else
            {
                // освобождение памяти из под данных
                for (node_t *cur = head; cur; cur = cur->next)
                    free(cur->data);

                list_free_all(head);
                free(data);
                return NULL;
            }
        }
        else
        {
            // освобождение памяти из под данных
            for (node_t *cur = head; cur; cur = cur->next)
                free(cur->data);

            list_free_all(head);
            return NULL;
        }
    }

    return head;
}

// функция для печати списка целых чисел
void list_nums_print(FILE *file, node_t *head)
{
    for (; head; head = head->next)
        fprintf(file, "%d ", *(int*)head->data);

    fprintf(file, "\n");
}
