/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** print_map.c
*/

#include "navy.h"

void print_map(char **map)
{
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int i = 0; map[i] != NULL; i++)
        my_printf("%s\n", map[i]);
}

void print_game(char **map, char **ennemy_map)
{
    my_printf("my positions:\n");
    print_map(map);
    my_printf("\nenemy's positions:\n");
    print_map(ennemy_map);
}