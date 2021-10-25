/*
** EPITECH PROJECT, 2019
** my_str_isalpha.c
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z')
            return 1;
        else
            return 0;
    i++;
    }
}