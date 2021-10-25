/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

int my_putstr(char const *str)
{
    int a;

    a = 0;
    while (str[a] != '\0') {
        my_putchar(str[a]);
        a = a + 1;
    }
}
