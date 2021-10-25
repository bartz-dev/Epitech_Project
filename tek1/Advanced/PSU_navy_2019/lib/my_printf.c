/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "navy.h"

int exception(va_list list, char *str, int i)
{
    switch (str[i + 1]) {
        case 'd':
            my_put_long(va_arg(list, long));
            break;
        case 'u':
            my_put_unsigned_long(va_arg(list, unsigned long));
            break;
        case 'x':
            base_hexa_long(va_arg(list, unsigned long));
            break;
        case 'o':
            base_long(va_arg(list, unsigned long), 8);
            break;
    }
}

void first_cond(va_list list, char *str, int i)
{
    switch (str[i]) {
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'i':
            my_put_nbr(va_arg(list, int));
            break;
        case 'd':
            my_put_nbr(va_arg(list, int));
            break;
        case 'l':
            exception(list, str, i);
            break;
        case 'u':
            my_put_unsigned_nbr(va_arg(list, unsigned int));
            break;
    }
}

void second_cond(va_list list, char *str, int i)
{
    switch (str[i]) {
        case 'o':
            base(va_arg(list, unsigned int), 8);
            break;
        case 'b':
            base(va_arg(list, unsigned int), 2);
            break;
        case 'x':
            base_hexa(va_arg(list, unsigned int));
            break;
        case 'X':
            base_hexa_upper(va_arg(list, unsigned int));
            break;
        case 'S':
            my_putnprintable(va_arg(list, char *));
            break;
        case '\n':
            my_putstr("%\n");
    }
}

int check_conditions(char *str, int i)
{
    if (str[i] == '%')
        my_putchar('%');
    if (str[i] == 'l' && (str[i + 1] == 'd' || str[i + 1] == 'o'
        || str[i + 1] == 'u' || str[i + 1] == 'x'))
        return 1;
    return 0;
}

int my_printf(char *str, ...)
{
    va_list list;
    int i = 0;

    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            first_cond(list, str, i);
            second_cond(list, str, i);
            if (check_conditions(str, i) == 1)
                i++;
        } else
            my_putchar(str[i]);
        i++;
    }
    va_end(list);
}