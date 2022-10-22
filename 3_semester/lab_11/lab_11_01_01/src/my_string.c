#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

size_t my_strlen(const char *s)
{
    int len = 0;

    while ('\0' != s[len])
        len++;

    return len;
}

int copy_str(char *s, const char *from, size_t n)
{
    for (size_t i = 0; i < n && '\0' != from[i]; i++)
        s[i] = from[i];

    return my_strlen(from);
}

// перевод числа в указанную сс
int convert_num_to_sys(char *buf, size_t size, unsigned num, unsigned base)
{
    int cnt = 0;
    unsigned copy = num;

    if (0 == num)
    {
        cnt = 1;
        buf[0] = DIGITS[0];
    }

    while (copy)
    {
        cnt++;
        copy /= base;
    }

    int res = cnt;

    while (cnt > size)
    {
        cnt--;
        num /= base;
    }

    cnt--;

    while (num)
    {
        buf[cnt] = DIGITS[num % base];
        cnt--;
        num /= base;
    }

    return res;
}

// перевод short числа в указанную сс
int convert_short_num_to_sys(char *buf, size_t size, unsigned short num, unsigned base)
{
    int cnt = 0;
    unsigned short copy = num;

    if (0 == num)
    {
        cnt = 1;
        buf[0] = DIGITS[0];
    }

    while (copy)
    {
        cnt++;
        copy /= base;
    }

    int res = cnt;

    while (cnt > size)
    {
        cnt--;
        num /= base;
    }

    cnt--;

    while (num)
    {
        buf[cnt] = DIGITS[num % base];
        cnt--;
        num /= base;
    }

    return res;
}

// перевод long числа в указанную сс
int convert_long_num_to_sys(char *buf, size_t size, unsigned long num, unsigned base)
{
    int cnt = 0;
    unsigned long copy = num;

    if (0 == num)
    {
        cnt = 1;
        buf[0] = DIGITS[0];
    }

    while (copy)
    {
        cnt++;
        copy /= base;
    }

    int res = cnt;

    while (cnt > size)
    {
        cnt--;
        num /= base;
    }

    cnt--;

    while (num)
    {
        buf[cnt] = DIGITS[num % base];
        cnt--;
        num /= base;
    }

    return res;
}

// перевод int в строку
int convert_int_to_str(char *s, size_t size, int num)
{
    int cnt = 0, res;

    if (num <= 0)
        cnt++;

    if (0 == num)
        s[0] = DIGITS[0];

    int copy = num;

    while (0 != copy)
    {
        cnt++;
        copy /= 10;
    }

    res = cnt;
    copy = num;

    while (cnt > size)
    {
        cnt--;
        num /= 10;
    }

    cnt--;

    while (0 != num)
    {
        s[cnt] = DIGITS[abs(num % 10)];
        cnt--;
        num /= 10;
    }

    if (copy < 0 && cnt >= 0)
        s[cnt] = '-';

    return res;
}

// перевод short int в строку
int convert_short_int_to_str(char *s, size_t size, short num)
{
    int cnt = 0, res;

    if (num <= 0)
        cnt++;

    if (0 == num)
        s[0] = DIGITS[0];

    short copy = num;

    while (0 != copy)
    {
        cnt++;
        copy /= 10;
    }

    res = cnt;
    copy = num;

    while (cnt > size)
    {
        cnt--;
        num /= 10;
    }

    cnt--;

    while (0 != num)
    {
        s[cnt] = DIGITS[abs(num % 10)];
        cnt--;
        num /= 10;
    }

    if (copy < 0 && cnt >= 0)
        s[cnt] = '-';

    return res;
}

// перевод long int в строку
int convert_long_int_to_str(char *s, size_t size, long num)
{
    int cnt = 0, res;

    if (num <= 0)
        cnt++;

    if (0 == num)
        s[0] = DIGITS[0];

    long copy = num;

    while (0 != copy)
    {
        cnt++;
        copy /= 10;
    }

    res = cnt;
    copy = num;

    while (cnt > size)
    {
        cnt--;
        num /= 10;
    }

    cnt--;

    while (0 != num)
    {
        s[cnt] = DIGITS[abs(num % 10)];
        cnt--;
        num /= 10;
    }

    if (copy < 0 && cnt >= 0)
        s[cnt] = '-';

    return res;
}

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list vl;
    int i = 0, j = 0, res = 0, len = 0;
    char ch;
    
    va_start(vl, format);

    while ('\0' != format[j])
    {
        if ('%' == format[j])
        {
            if ('c' == format[j + 1])
            {
                ch = va_arg(vl, int);

                if (i < (int)n - 1)
                    s[i++] = ch;

                res++;
            }
            else if ('d' == format[j + 1] || 'i' == format[j + 1])
            {
                len = convert_int_to_str(s + i, n - i - 1, va_arg(vl, int)); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
            }
            else if ('x' == format[j + 1])
            {
                len = convert_num_to_sys(s + i, n - i - 1, va_arg(vl, unsigned), 16);

                if (i < (int)n - 1)
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
            }
            else if ('o' == format[j + 1])
            {
                len = convert_num_to_sys(s + i, n - i - 1, va_arg(vl, unsigned), 8);

                if (i < (int)n - 1)
                    i += len < (n - i - 1) ? len : (n - i - 1);
                    
                res += len;
            }
            else if ('s' == format[j + 1])
            {
                len = copy_str(s + i, va_arg(vl, char*), n - i - 1);

                if (i < (int)n - 1)
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
            }
            else if ('%' == format[j + 1])
            {
                if (i < (int)n - 1)
                    s[i++] = '%';

                res++;
            }
            else if ('h' == format[j + 1] && ('d' == format[j + 2] || 'i' == format[j + 2]))
            {
                len = convert_short_int_to_str(s + i, n - i - 1, va_arg(vl, int)); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
                j++;
            }
            else if ('h' == format[j + 1] && 'x' == format[j + 2])
            {
                len = convert_short_num_to_sys(s + i, n - i - 1, va_arg(vl, unsigned), 16); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
                j++;
            }
            else if ('h' == format[j + 1] && 'o' == format[j + 2])
            {
                len = convert_short_num_to_sys(s + i, n - i - 1, va_arg(vl, unsigned), 8); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
                j++;
            }
            else if ('l' == format[j + 1] && ('d' == format[j + 2] || 'i' == format[j + 2]))
            {
                len = convert_long_int_to_str(s + i, n - i - 1, va_arg(vl, long int)); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
                j++;
            }
            else if ('l' == format[j + 1] && 'x' == format[j + 2])
            {
                len = convert_long_num_to_sys(s + i, n - i - 1, va_arg(vl, unsigned long), 16); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
                j++;
            }
            else if ('l' == format[j + 1] && 'o' == format[j + 2])
            {
                len = convert_long_num_to_sys(s + i, n - i - 1, va_arg(vl, unsigned long), 8); 

                if (i < (int)n - 1)    
                    i += len < (n - i - 1) ? len : (n - i - 1);

                res += len;
                j++;
            }
            else
                return -1;

            j += 2;
        }
        else
        {
            if (i < (int)n - 1)
                s[i++] = format[j];

            res++;
            j++;
        }
    }

    if (s)
        s[i] = '\0';

    va_end(vl);
    return res;
}
