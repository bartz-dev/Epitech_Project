/*
** EPITECH PROJECT, 2019
** my_strsplit
** File description:
** my_strsplit
*/

#include <stdlib.h>
#include "tools.h"

char **my_strslice(char *str, int pos)
{
    char **result = malloc(sizeof(char *) * 3);

    str[pos] = '\0';
    result[0] = my_strdup(str);
    result[1] = my_strdup(str + pos + 1);
    result[2] = 0;
    return result;
}