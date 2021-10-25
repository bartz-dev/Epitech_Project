/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** pos_error.c
*/

#include "navy.h"

int getnbrlinepos(char *buff)
{
    int lines = 0;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            lines++;
    if (lines != 4)
        return 1;
    return 0;
}

int getnbrcolpos(char *buff)
{
    int col = 0;
    int j = 1;

    for (int i = 0; buff[i] != '\0'; i++, j++) {
        if (buff[i] == '\n' && buff[i + 1] == '\0')
            return 0;
        if (buff[i] == '\n' && j != 8)
            return 1;
        if (buff[i] == '\n')
            j = 0;
    }
    return 0;
}

int check_strpos(char **pos)
{
    int i = 0;
    int shiptype = 2;

    for (int j = 0; pos[i] != NULL ; i++, j = 0, shiptype++) {
        if (pos[i][1] != ':' || pos[i][4] != ':')
            return 1;
        if (isnum(pos[i][0]) == 0 || isnum(pos[i][3]) == 0
            || isnum(pos[i][6]) == 0)
            return 1;
        if (char_isalpha(pos[i][2]) == 0 || char_isalpha(pos[i][5]) == 0)
            return 1;
        if (shiptype != (i + 2))
            return 1;
    }
}
