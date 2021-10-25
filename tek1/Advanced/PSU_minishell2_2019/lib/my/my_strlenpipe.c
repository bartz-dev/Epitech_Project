/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_strlenpipe.c
*/

#include "my.h"

int my_strlenpipe(char *str)
{
    int i = 0;
    int p = 0;

    while (str[i] != '|')
        i++;
    if (str[i] == '|') {
        while (str[i] == '|') {
            p++;
            i++;
        }
        return p;
    }
    return 0;
}