/*
** EPITECH PROJECT, 2019
** my_putfloat
** File description:
** Displays a float
*/

#include "tools.h"

int get_number_of_digits(int nb)
{
    int i = 0;

    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return (i);
}

int my_putfloat(float f, int decimals)
{
    int power_of_ten = get_power_of_ten(decimals);
    int must_be_rounded_up = (int)(f * power_of_ten * 10) % 10 >= 5;
    int digits = (int)(f * power_of_ten) % power_of_ten;
    int i = digits;

    my_put_nbr(decimals == 0 ? f + must_be_rounded_up : f);
    if (decimals != 0) {
        my_putchar('.');
        while (decimals > get_number_of_digits(i)) {
            my_putchar('0');
            i = i == 0 ? 10 : i * 10;
        }
        my_put_nbr(digits + must_be_rounded_up);
    }
    return (0);
}
