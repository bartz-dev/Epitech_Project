/*
** EPITECH PROJECT, 2019
** my_strconcat
** File description:
** my_strconcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strconcat(char const *str1, char const *str2)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2)
        + 1));

    my_strcat(new_str, str1);
    my_strcat(new_str, str2);
    new_str[my_strlen(str1) + my_strlen(str2)] = '\0';
    return new_str;
}