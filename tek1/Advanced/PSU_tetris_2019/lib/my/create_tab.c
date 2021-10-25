/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** char * to char ** by clément Fleur
*/

#include <stdlib.h>
#include "my.h"
#include "match.h"
#include <stdio.h>

char **writegame(match_t *match, char **str)
{
    int i = 0;
    int l = 1;
    int c = match->line - 1;
    int count = 0;

    match->pipe = 0;
    while (i < match->line) {
        while (count < i + l) {
            c++;
            str[l][c] = '|';
            match->pipe++;
            count++;
        }
        l++;
        c = c - (2 * (l-1));
        count = 0;
        i++;
    }
    return str;
}

char **writemap(match_t *match, char **str)
{
    int i = 1;
    int p = 0;

    while (i < match->line + 1) {
        p = 1;
        while (p < match->line * 2) {
            str[i][p] = ' ';
            p++;
        }
        str[i][0] = '*';
        str[i][match->line * 2] = '*';
        i++;
    }
    i = 0;
    writegame(match, str);
    while (i < match->line + 2) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
    return str;
}

char **my_strtodouble(match_t *match)
{
    char **new_str;
    int i = 0;

    new_str = malloc(sizeof(*new_str) * (match->line * 2 + 1));
    if (new_str == NULL)
        my_putstr("error");
    while (i < (match->line + 2)) {
        new_str[i] = malloc(sizeof(char) * ((match->line * 2) + 1));
        new_str[i][match->line * 2 + 1] = 0;
        i = i + 1;
    }
    i = 0;
    while (i < match->line * 2 + 1) {
        new_str[0][i] = '*';
        new_str[match->line + 1][i] = '*';
        i++;
    }
    writemap(match, new_str);
    return new_str;
} 