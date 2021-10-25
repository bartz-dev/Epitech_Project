/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d02_2019
** File description:
** is_prime_number.c
*/

#include "phoenix.h"

int is_prime_number(int nb)
{
    if (nb <= 1)
        return (0);
    for (int digit = 2; digit < nb; digit++) {
        if (nb % digit == 0)
            return (0);
    }
    return (1);
}