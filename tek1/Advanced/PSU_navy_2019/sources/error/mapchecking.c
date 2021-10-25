/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** mapchecking.c
*/

#include "navy.h"

int findposy(char **map, int nbr_pos, int letter_pos, char *pos)
{
    int i = letter_pos;

    if (pos[2] != pos[5]) {
        while (map[nbr_pos][i] != '.')
            i++;
        return i;
    }
    return letter_pos;
}

int findposx(char **map, int nbr_pos, int letter_pos, char *pos)
{
    int i = nbr_pos;

    if (pos[2] == pos[5]) {
        while (map[i][letter_pos] != '.')
            i++;
        return i;
    }
    return nbr_pos;
}

char **write_right(char **map, int nbr1_pos, int letter_pos, char *pos)
{
    map[nbr1_pos][letter_pos] = map[nbr1_pos][letter_pos - 2];
    return map;
}

char **write_down(char **map, int nbr1_pos, int letter_pos, char *pos)
{
    map[nbr1_pos][letter_pos] = map[nbr1_pos - 1][letter_pos];
    return map;
}