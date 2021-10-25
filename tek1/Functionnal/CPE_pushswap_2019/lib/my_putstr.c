/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr by clement fleur
*/

#include "pushswap.h"

void my_put_str(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_put_char(str[i]);
        i++;
    }
    my_put_char('\0');
}
