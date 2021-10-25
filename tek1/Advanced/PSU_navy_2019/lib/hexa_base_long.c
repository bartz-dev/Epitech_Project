/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** hexa_base.c
*/

#include "navy.h"

void exception_hexa_long(unsigned long i)
{
    switch (i){
        case 10:
            my_putchar('a');
            break;
        case 11:
            my_putchar('b');
            break;
        case 12:
            my_putchar('c');
            break;
        case 13:
            my_putchar('d');
            break;
        case 14:
            my_putchar('e');
            break;
        case 15:
            my_putchar('f');
            break;
    }
}

void base_hexa_long(unsigned long i)
{
    if (i == 0)
        return;
    base_hexa_long(i / 16);
    if ((i % 16) >= 10)
        exception_hexa_long(i % 16);
    else
        my_put_nbr(i % 16);
}