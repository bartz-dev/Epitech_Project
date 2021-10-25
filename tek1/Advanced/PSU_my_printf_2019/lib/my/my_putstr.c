/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays the given string
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
