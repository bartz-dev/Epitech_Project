/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d01_2019
** File description:
** reverse_string.c
*/

#include "phoenix.h"

char * my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    char dest[i];

    for (int t = 0; t < my_strlen(str); t++) {
        dest[t] = str[i];
        i--;
    }
    my_putstr(dest);
    return (dest);
}