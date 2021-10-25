/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** by clement fleur Promo 2024
*/

#include "struct.h"
#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

struct printf_a tab[] = {
    {'s', my_putstr}, {'c', my_putchar}, {'d', my_put_nbr},
    {'i', my_put_nbr}, {'S', my_putstr}, {0, }
};

void check_type(char av, va_list list)
{
    int i;

    i = 0;
    if (av != tab[2].flag && av != tab[3].flag) {
        while (tab[i].flag != av) {
            i++;
        }
        tab[i].fct(va_arg(list, char *));
    }
    else {
        while (tab[i].flag != av) {
            i++;
        }
        tab[i].fct(va_arg(list, int));
    }
}

void my_printf(char *av, ...)
{
    int i;
    va_list list;

    i = 0;
    va_start(list, av);
    while (av[i] != 0) {
        if (av[i] == '%')
            check_type(av[i + 1], list);
        else if (av[i - 1] != '%')
            my_putchar(av[i]);
        i++;
    }
    va_end(list);
}
