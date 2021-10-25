/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** game.c
*/

#include "my.h"
#include "match.h"
#include <stdio.h>
#include <stdlib.h>


int checkerror_output(int nbr, match_t *match, char **str, int line)
{
    if (nbr > match->max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(match->max);
        my_putstr(" matches per turn\n");
        return 84;
    }
    else if (nbr == 0 || pipecount(str[line]) < nbr) {
        my_putstr("Error: not enough matches on this line\n");
        return 84;
    }
}
void iaturn(char **str, match_t *match)
{
    int matches = rand() % match->max + 1;
    int line = 0;

    while (my_strlenpipe(str[line]) == 0)
        line = rand() % match->line + 1;
    while (matches > pipecount(str[line]))
        matches = rand() % match->max + 1;
    my_putstr("AI's turn...\nAI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from Line ");
    my_put_nbr(line);
    my_putchar('\n');
    remove_pipe(str, match, matches, line);
    if (match->pipe == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        match->win = 8;
    }
}

void write_game(char **str, match_t *match)
{
    int i = 0;

    while (i < match->line + 2) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
}

void remove_pipe(char **str, match_t *match, int nbr, int line)
{
    int i = 1;

    while (str[line][i] != '*')
        i++;
    i--;
    while (str[line][i] == ' ')
    {
        i--;
    }
    while (nbr != 0) {
        str[line][i] = ' ';
        nbr--;
        i--;
        match->pipe--;
        if (str[line][i]  == ' ' || str[line][i] == '*')
            break;
    }
    write_game(str, match);
}

int startgame(char **str, match_t *match, char *str2)
{
    size_t len = 1;
    int line;
    int nbr;

    while (match->pipe != 0) {
        my_putstr("Your turn:\n");
        my_putstr("Line: ");
        if (getline(&str2, &len, stdin) <= 0) return 0;
        line = my_getnbr(str2);
        if (check_line(str, line, match, str2) == 84) return 0;
        else my_putstr("Matches: ");
        if (getline(&str2, &len, stdin) <= 0) return 0;
        nbr = my_getnbr(str2);
        if (checkerror_output(nbr, match, str, line) == 84)
            startgame(str, match, str2);
        else { writeplayerinfo(nbr, line);
            remove_pipe(str, match, nbr, line);
        }
        match->pipe == 0 ? nbr = nbr : iaturn(str, match);
    }
}