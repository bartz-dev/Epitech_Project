/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_putnbr
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

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
