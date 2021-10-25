/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (str[i] >= 0 && str[i] <= 31 || str[i] == 127)
            return 0;
        else
            return 1;
    i++;
    }
}