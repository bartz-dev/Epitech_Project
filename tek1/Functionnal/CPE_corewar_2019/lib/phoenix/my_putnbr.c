/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d01_2019
** File description:
** main.c
*/

#include "phoenix.h"
#include <stdlib.h>
#include <unistd.h>

int my_putnbr(int nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 84;
    }
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
        if (nb > 10)
            my_putnbr((nb / 10));
        my_putchar((nb % 10) + '0');
    }
    else{
        if (nb >= 10)
            my_putnbr(nb / 10);
            my_putchar((nb % 10) + '0');

        if (nb <= 10) {
            my_putchar(nb % 10);

            }
    }
}
