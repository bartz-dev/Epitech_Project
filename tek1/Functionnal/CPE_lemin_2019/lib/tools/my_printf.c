/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "tools.h"

int process_type(char type, va_list args)
{
    switch (type)
    {
    case 'd':
        return my_put_nbr(va_arg(args, int));
    case 'i':
        return my_put_nbr(va_arg(args, int));
    case 'f':
        return my_putdouble(va_arg(args, double), 6, 1);
    case 'F':
        return my_putdouble(va_arg(args, double), 6, 1);
    case 'c':
        return my_putchar(va_arg(args, int));
    case 's':
        return my_putstr(va_arg(args, char *));
    case '%':
        return my_putchar('%');
    default:
        return 0;
    }
}

int my_printf(char const *format, ...)
{
    va_list args;
    int i = 0;

    va_start(args, format);
    while (format[i]) {
        if (format[i] == '%' && format[i + 1]) {
            process_type(format[i + 1], args);
            i++;
        } else my_putchar(format[i]);
        i++;
    }
    va_end(args);
    return 0;
}