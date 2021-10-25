/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** my_strncat
*/

#include "tools.h"

char *my_strncat(char *dest, char const *str, int n)
{
    int len = my_strlen(dest);
    int i = 0;

    while (str[i] && i < n) {
        dest[len + i] = str[i];
        i++;
    }
    return dest;
}
