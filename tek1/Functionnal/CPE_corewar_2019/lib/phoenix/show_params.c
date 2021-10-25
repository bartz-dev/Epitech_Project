/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d03_2019
** File description:
** show_params.c
*/

#include "phoenix.h"

int show_params (int ac, char **av)
{
    for (int i = 0; i < ac; i++) {
        my_putstr(av[i]);
        my_putstr("\n");
    }
    return 0;
}
