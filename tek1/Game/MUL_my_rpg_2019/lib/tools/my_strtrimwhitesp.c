/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** my_strtrimwhitesp
*/

#include "tools.h"
#include <stdlib.h>

int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

char *my_strtrimwhitesp(char *str)
{
    int count = 0;
    char *new_str;
    int i = 0;

    for (i = 0; str[i]; i++)
        if (is_whitespace(str[i]))
            count++;
    new_str = malloc(sizeof(char) * (my_strlen(str) - count + 1));
    count = 0;
    for (i = 0; str[i]; i++) {
        if (is_whitespace(str[i]))
            count++;
        else
            new_str[i - count] = str[i];
    }
    new_str[i - count] = 0;
    return new_str;
}

char *my_trim_keep_str(char *str)
{
    int count = 0;
    int trim = 0;
    char *new_str;
    int i = 0;

    for (i = 0; str[i]; i++)
        if (is_whitespace(str[i]) && trim) count++;
        else if (str[i] == '"' && (i == 0 || str[i - 1] != '\\')) trim = !trim;
    new_str = malloc(sizeof(char) * (my_strlen(str) - count + 1));
    count = 0;
    trim = 1;
    for (i = 0; str[i]; i++) {
        if (is_whitespace(str[i]) && trim) count++;
        else {
            if (str[i] == '"' && (i == 0 || str[i - 1] != '\\')) trim = !trim;
            new_str[i - count] = str[i];
        }
    }
    new_str[i - count] = 0;
    return new_str;
}