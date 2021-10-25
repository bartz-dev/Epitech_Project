/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

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