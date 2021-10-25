/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_collision.c
*/

#include "navy.h"

char **redirecting(char **map, int nbr1_pos, int letter_pos, char *pos)
{
    if (pos[2] == pos[5])
        map = write_down(map, nbr1_pos, letter_pos, pos);
    else if (pos[2] != pos[5])
        map = write_right(map, nbr1_pos, letter_pos, pos);
    return map;
}

char **write_boat(char **map, char *pos, int boatnbr)
{
    int cols = 2;
    int letter_pos = 0;
    char *letter = " |A B C D E F G H";
    int nbr1_pos = pos[cols + 1] - '0' - 1;

    while (pos[cols] != letter[letter_pos])
        letter_pos++;
    map[nbr1_pos][letter_pos] = (boatnbr + 48);
    for (int i = 1; i != boatnbr; i++) {
        nbr1_pos = findposx(map, nbr1_pos, letter_pos, pos);
        letter_pos = findposy(map, nbr1_pos, letter_pos, pos);
        map = redirecting(map, nbr1_pos, letter_pos, pos);
    }
    return map;
}

char **strategical_add(char **map, char **pos)
{
    int boatnbr = 2;
    int j = 2;

    for (int i = 0; pos[i] != NULL; i++, boatnbr++) {
        map = write_boat(map, pos[i], boatnbr);
    }
    return map;
}

int check_not_diagonal(char *pos, int nbr)
{
    int nbr1 = pos[6] - '0';
    int nbr2 = pos[3] - '0';
    int nbr3 = pos[2] - 'A';
    int nbr4 = pos[5] - 'A';
    char coef = nbr + '0';
    int checker = 0;

    if (pos[0] == coef) {
        if ((pos[2] == pos[5]) && (nbr1 - nbr2 == nbr - 1))
            checker++;
        if ((pos[3] == pos[6]) && (nbr4 - nbr3 == nbr - 1))
            checker++;
    }
    return checker;
}

int check_collision(char **pos)
{
    int checker = 0;
    int nbr = 2;
    for (int i = 0; i <= 3; i++, nbr++) {
        checker = check_not_diagonal(pos[i], nbr);
        if (checker != 1)
            return 1;
    }
    return 0;
}