/*
** EPITECH PROJECT, 2019
** my_strconcat
** File description:
** my_strconcat
*/

#include "tools.h"
#include <stdlib.h>

char *my_strconcat(char const *str1, char const *str2)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)
        + 1));

    for (int i = 0; i <= my_strlen(str1) + my_strlen(str2); i++)
        new_str[i] = 0;
    my_strcat(new_str, str1);
    my_strcat(new_str, str2);
    return new_str;
}