/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

long my_put_long(long nb)
{
    if (nb > 9)
        my_put_long(nb / 10);
    else if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        my_put_long(nb / 10);
    }
    my_putchar('0' + nb % 10);
}