/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** my_isneg by clement fleur
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

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
