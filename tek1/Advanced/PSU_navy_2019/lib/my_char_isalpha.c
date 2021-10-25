/*
** EPITECH PROJECT, 2019
** my_char_isalpha.c
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

int my_char_isalpha(char str)
{
    if (str == '\0')
        return 1;
    if (str >= 'A' && str <= 'Z' || str >= 'a' && str <= 'z')
        return 1;
    else
        return 0;
}