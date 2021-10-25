/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** base.c
*/

#include "navy.h"

void base(unsigned int i, int b)
{
    if (i == 0)
        return;
    base(i / b, b);
    my_put_nbr(i % b);
}