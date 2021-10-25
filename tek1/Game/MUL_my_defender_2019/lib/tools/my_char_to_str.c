/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** my_char_to_str
*/

#include <stdlib.h>

char *my_char_to_str(char c)
{
    char *str = malloc(sizeof(char) * 2);

    str[0] = c;
    str[1] = 0;
    return str;
}