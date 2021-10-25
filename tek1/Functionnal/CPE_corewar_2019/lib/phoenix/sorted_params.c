/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d03_2019
** File description:
** sorted_params.c
*/

#include "phoenix.h"

int sorted_params (int ac, char **av)
{
    int final = 0;
    char *save;

    while (final == 0) {
        final++;
        for (int i = 0; i < (ac - 1); i++) {
            if (my_strncmp(av[i], av[i + 1], 500) > 0) {
                final--;
                save = av[i];
                av[i] = av[i + 1];
                av[i + 1] = save;
            }
        }
    }
    for (int i = 0; i < ac; i++) {
        my_putstr(av[i]);
        my_putstr("\n");
    }
}