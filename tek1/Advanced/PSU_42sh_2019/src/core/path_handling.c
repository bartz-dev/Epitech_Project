/*
** EPITECH PROJECT, 2020
** path_handling
** File description:
** path_handling
*/

#include "shell.h"
#include <stdlib.h>

int get_path_line(char *path)
{
    int incr = 0;
    int line_count = 0;

    while (path[incr] != 0) {
        if (path[incr] == ':') line_count++;
        incr++;
    }
    return line_count;
}

char **malloc_parsed_path(char **parsed_path, char *path)
{
    int line_count = get_path_line(path);
    int line_lenght = my_strlen(path);
    int incr = 0;

    parsed_path = malloc(sizeof(char *) * line_count + 1);
    while (incr < line_count + 1) {
        parsed_path[incr] = malloc(sizeof(char) * line_lenght);
        incr++;
    }
    parsed_path[incr] = 0;
    return parsed_path;
}

char **parse_path(char *path)
{
    char **parsed_path = malloc_parsed_path(parsed_path, path);
    int line = 0;
    int incr_p = 0;
    int incr_new_p = 0;

    while (path[incr_p] != 0) {
        if (path[incr_p] == ':') {
            parsed_path[line][incr_new_p] = 0;
            line++;
            incr_p++;
            incr_new_p = 0;
        }
        parsed_path[line][incr_new_p++] = path[incr_p++];
    }
    return parsed_path;
}