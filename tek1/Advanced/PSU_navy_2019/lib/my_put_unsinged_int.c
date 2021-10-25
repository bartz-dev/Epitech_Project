/*
** EPITECH PROJECT, 2019
** my_put_unsinged_int.c
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

unsigned int my_put_unsigned_nbr(unsigned int nb)
{
    if (nb > 9)
        my_put_unsigned_nbr(nb / 10);
    my_putchar('0' + nb % 10);
}