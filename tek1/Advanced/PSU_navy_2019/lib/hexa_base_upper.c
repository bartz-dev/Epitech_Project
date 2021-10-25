/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** hexa_base_upper.c
*/

#include "navy.h"

void exception_upper(int i)
{
    switch (i){
        case 10:
            my_putchar('A');
            break;
        case 11:
            my_putchar('B');
            break;
        case 12:
            my_putchar('C');
            break;
        case 13:
            my_putchar('D');
            break;
        case 14:
            my_putchar('E');
            break;
        case 15:
            my_putchar('F');
            break;
    }
}

void base_hexa_upper(unsigned int i)
{
    if (i == 0)
        return;
    base_hexa_upper(i / 16);
    if ((i % 16) >= 10)
        exception_upper(i % 16);
    else
        my_put_nbr(i % 16);
}