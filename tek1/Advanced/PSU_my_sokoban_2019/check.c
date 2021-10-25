/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** check.c
*/

#include <stdio.h>
#include "my.h"

void help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n     map  file representing the warehouse map,");
    my_putstr(" containing '#' for walls,\n\t  'P' for the player, 'X' ");
    my_putstr("for boxes and '0' for storage locations.");
}

void check_error(int ac, char **argv)
{
    if (ac == 1)
        return 84;
    else if (my_strcmp(argv[1], "-h") == 1 && ac == 2)
        help();
    else
        return ac;
}