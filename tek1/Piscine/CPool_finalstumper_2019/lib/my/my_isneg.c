/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** my_isneg by clement fleur
*/

#include <unistd.h>
#include "rush3.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    }
    else {
        my_putchar('P');
    }
    return 0;
}
