/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Displays provided number
*/

#include "tools.h"

int get_power_of_ten(int n)
{
    int nb;

    nb = 1;
    while (n > 0) {
        nb *= 10;
        n--;
    }
    return (nb);
}

int get_digit(int nb, int n)
{
    while (n > 1) {
        nb /= 10;
        n--;
    }
    return (nb % 10);
}

int my_put_nbr(int nb)
{
    if (nb < -2147483647)
        my_putstr("-2147483648");
    if (nb < 0)
    {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb >= 10)
    {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else
        my_putchar(nb + '0');
    return (0);
}
