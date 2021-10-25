/*
** EPITECH PROJECT, 2019
** my_putdouble
** File description:
** Displays a double
*/

#include "tools.h"

int my_putdouble(double d, int decimals, int remove_zeros)
{
    int power_of_ten = get_power_of_ten(decimals);
    int must_be_rounded_up = (int)(d * power_of_ten * 10) % 10 >= 5;
    int digits = (int)(d * power_of_ten) % power_of_ten;
    int i = digits;

    my_put_nbr(decimals == 0 ? d + must_be_rounded_up : d);
    if (decimals != 0) {
        my_putchar('.');
        while (decimals > get_number_of_digits(i)) {
            my_putchar('0');
            i = i == 0 ? 10 : i * 10;
        }
        while (remove_zeros && must_be_rounded_up == 0 && digits % 10 == 0) {
            digits /= 10;
        }
        my_put_nbr(digits + must_be_rounded_up);
    }
    return (0);
}
