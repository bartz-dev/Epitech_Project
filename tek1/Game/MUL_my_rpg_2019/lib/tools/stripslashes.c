/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** stripslashes
*/

#include <stdlib.h>
#include "tools.h"

void check_slash(char *str, int *had_slash, int *count, int i)
{
    if (str[i] == '\\') {
        *had_slash = !(*had_slash);
        *count += *had_slash;
    } else *had_slash = 0;
}

char *stripslashes(char *str)
{
    int had_slash = 0;
    int count = -1;
    char *new_str;
    int i;

    for (i = 0; str[i]; i++)
        check_slash(str, &had_slash, &count, i);
    new_str = malloc(sizeof(char) * (my_strlen(str) - count));
    had_slash = 0;
    count = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != '\\' || had_slash) new_str[i - count] = str[i];
        check_slash(str, &had_slash, &count, i);
    }
    new_str[i] = 0;
    return new_str;
}