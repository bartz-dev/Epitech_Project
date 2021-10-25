/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d02_2019
** File description:
** my_strcpy.c
*/

#include "phoenix.h"

char *my_strcpy(char *dest, char const *src)
{
    int pos;
    for (pos = 0; src[pos] != '\0'; pos++) {
        dest[pos] = src[pos];
    }
    dest[pos] = '\0';
    return (dest);
}