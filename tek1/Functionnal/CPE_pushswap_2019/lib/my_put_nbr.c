/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include "pushswap.h"

void my_put_nbr(int nbr)
{
    if (nbr == -2147483648)
        my_put_str("-2147483648");
    else if (nbr < 0)
    {
        my_put_char('-');
        nbr *= -1;
        my_put_nbr(nbr);
    }
    else if (nbr >= 10)
    {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
    else
        my_put_char(nbr + '0');
}
