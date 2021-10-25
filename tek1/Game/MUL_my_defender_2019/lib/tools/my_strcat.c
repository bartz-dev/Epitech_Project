/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "tools.h"

char *my_strcat(char *dest, char const *str)
{
    int len = my_strlen(dest);
    int i = 0;

    while (str[i]) {
        dest[len + i] = str[i];
        i++;
    }
    return dest;
}
