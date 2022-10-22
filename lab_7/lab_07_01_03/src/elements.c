#include "element.h"
#include "elements.h"

// функция для подсчета числа элементов во входном файле
int calc_elements(FILE *in, size_t *cnt)
{
    if (NULL == in || NULL == cnt)
        return INVALID_PARAM_ERROR;

    *cnt = 0;

    int elem;

    while (1 == fscanf(in, "%d", &elem))
        (*cnt)++;

    if (0 == *cnt)
        return EMPTY_FILE;

    if (feof(in))
        return EXIT_SUCCESS;

    return READ_ERROR;
}

// функция для чтения элементов из массива
int read_elements(FILE *in, int *arr, const size_t cnt, int **pe)
{
    if (NULL == in || NULL == arr || cnt == 0 || NULL == pe)
        return INVALID_PARAM_ERROR;

    int *pb = arr;

    for (size_t i = 0; i < cnt; i++)
    {
        if (1 != fscanf(in, "%d", pb))
            return READ_ERROR;

        pb++;
    }

    *pe = pb;

    return EXIT_SUCCESS;
}

// функция для фильтрации массива
int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst)
{
    if (NULL == pb_src || NULL == pe_src || NULL == pb_dst || NULL == pe_dst || pe_src <= pb_src)
        return INVALID_PARAM_ERROR;

    int *pa = pe_src - 1, cnt = 0;
    // пока не дошли до начала исходного массива
    while (pa >= pb_src)
    {
        // встретился отрицательный элемент
        if ((*pa) < 0)
            break;

        pa--;
    }
    
    // в массиве нет ни одного отрицательного элемента
    if (pa < pb_src)
    {
        cnt = pe_src - pb_src;
        pa = pe_src;
    }
    else if (pa > pb_src)
        // в массиве есть отрицательный элемент (не первый)
        cnt = pa - pb_src;
    else
        // первый элемент - единственный меньше 0
        return FILTER_ERROR;

    *pb_dst = malloc(cnt * sizeof(int));
    // Проверка успешности выделения
    if (*pb_dst == NULL)
        return MEMORY_ERROR;

    *pe_dst = *pb_dst;
    // пока не дошли до последнего отрицательного элемента в исходном массиве
    while (pb_src < pa)
    {
        **pe_dst = *pb_src;
        pb_src++;
        (*pe_dst)++;
    }

    return EXIT_SUCCESS;
}

// функция для сортировки массива по возрастанию
int mysort(void *arr, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    if (NULL == arr || 0 == nmemb || 0 == size || NULL == compar)
        return INVALID_PARAM_ERROR;

    for (char *pi = (char*)arr + (nmemb - 1) * size; pi > (char*)arr; pi -= size)
    {
        // максимальный элемент массива
        char *pm = pi;

        for (char *pj = pi - size; pj >= (char*)arr; pj -= size)
            if (compar(pm, pj) < 0)
                pm = pj;
        
        swap_elements(pm, pi, size);
    }

    return EXIT_SUCCESS;
}

// функция для печати элементов массива
int print_elements(FILE *out, const int *pb, const int *pe)
{
    if (NULL == out || NULL == pb || NULL == pe)
        return INVALID_PARAM_ERROR;

    while (pb < pe)
    {
        fprintf(out, "%d ", *pb);
        pb++;
    }

    return EXIT_SUCCESS;
}
