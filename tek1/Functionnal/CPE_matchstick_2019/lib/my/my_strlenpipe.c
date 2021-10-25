/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** my_strlenpipe.c
*/

#include "my.h"
#include "match.h"
#include <stdio.h>

void writeplayerinfo(int nbr, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(nbr);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int check_line(char **str, int line, match_t *match, char *str2)
{
    if (match->line < line || pipecount(str[line]) == 0 || str[line][1] == '*'
        || line == 0) {
        my_putstr("Error: this line is out of range\n");
        startgame(str, match, str2);
        return 84;
    }
}

int pipecount(char *str)
{
    int i = 1;
    int p = 0;

    while (str[i] == ' ')
        i++;
    while (str[i] == '|') {
        i++;
        p++;
    }
    return p;
}

int my_strlenpipe(char *str)
{
    int i = 1;
    int p = 0;

    while (str[i] != '*') {
        if (str[i] == '|')
            return 1;
        i++;
    }
    return 0;
}