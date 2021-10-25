/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

unsigned long my_put_unsigned_long(unsigned long nb)
{
    if (nb > 9)
        my_put_unsigned_long(nb / 10);
    my_putchar('0' + nb % 10);
}