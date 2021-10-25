/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "my.h"
#include "match.h"
#include <stdlib.h>
#include <stdio.h>

int error_handling(char **argv, match_t *match, int ac)
{
    if (ac <= 2 || my_getnbr(argv[1]) <= 1 || my_getnbr(argv[2]) <= 0) {
        my_putstr("error can't play with less 2 size/less than 2 arguments !");
        return 84;
    }
    match->line = my_getnbr(argv[1]);

    return 0;
}

int main(int ac, char **argv)
{
    match_t *match = malloc(sizeof(match));
    char **str;
    char *str2;

    if (error_handling(argv, match, ac) == 84)
        return 84;
    match->max = malloc(sizeof(int) * 1);
    match->max = my_getnbr(argv[2]);
    str = my_strtodouble(match);
    str2 = malloc(sizeof(char) * my_getnbr(argv[2]));
    match->turn = 0;
    startgame(str, match, str2);
    free(str);
    free(str2);
    if (match->win != 8 && match->pipe == 0) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    if (match->pipe == 0) return 1;
    else return 0;
}