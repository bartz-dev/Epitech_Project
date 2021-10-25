/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d03_2019
** File description:
** concat_strings.c
*/

#include "phoenix.h"

char *concat_strings(char *dest, char const *src)
{
    int len = my_strlen(dest);

    for (int i = 0; src[i]; i++) {
        dest[len] = src[i];
        len++;
    }
    dest[len] = '\0';
    return (dest);
}