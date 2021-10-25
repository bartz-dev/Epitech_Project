/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** file.c
*/

#include "tools.h"
#include "lemin.h"

void cmdnbr_check(char *path, int i, int check[])
{
    char *start = "start";
    char *end = "end";
    char *new_str = malloc(sizeof(char) * 5);
    int p = 0;

    while (p != my_strlen(start)) {
        if (start[p] == path[i])
            new_str[p] = path[i];
        else if (end[p] == path[i]) {
            new_str[p] = path[i];
        }
        p++;
        i++;
    }
    if (!my_strcmp(new_str, start) == 1)
        check[0]++;
    if (!my_strcmp(new_str, end) == 1)
        check[1]++;
    free(new_str);
}

int checkfile_error(char *filepath)
{
    int i = 0;
    int check[] = {0, 0};

    filepath = read_file(filepath);
    my_putstr(filepath);
    while (filepath[i] != 0) {
        if (filepath[i] == '#' && filepath[i + 1] == '#') {
            cmdnbr_check(filepath, i + 2, &check);
        }
        i++;
    }
    if (check[0] == 1 && check[1] == 1)
        return 0;
    else
        return 84;
}