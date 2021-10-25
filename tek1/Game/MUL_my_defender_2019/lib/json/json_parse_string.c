/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_parse_string
*/

#include "tools.h"

char *json_parse_string(char **cursor)
{
    int ignore_next = 0;
    char *str;

    if ((*cursor)[0] != '"') {
        my_printf("invalid json\n");
        return 0;
    }
    str = ++(*cursor);
    while ((*cursor)[0] != '"' || ignore_next) {
        if((*cursor)[0] == '\\') ignore_next = !ignore_next;
        else ignore_next = 0;
        (*cursor)++;
    }
    (*cursor)[0] = 0;
    (*cursor)++;
    str = stripslashes(str);
    return str;
}