/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** Duplicates a string
*/

#include <stdlib.h>
#include "tools.h"

char *my_strdup(char const *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(new_str, str);
    return (new_str);
}
