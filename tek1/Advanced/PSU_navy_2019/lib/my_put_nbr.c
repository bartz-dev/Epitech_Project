/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

int my_put_nbr(int nb)
{
    if (nb > 9)
        my_put_nbr(nb / 10);
    else if (nb < 0) {
        nb *= -1;
        my_putchar('-');
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + nb % 10);
}