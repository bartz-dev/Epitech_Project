/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** memory.c
*/

#include "navy.h"

void save_pos(char *buff, char ***pos)
{
    int i = 0;
    int j = 0;

    (*pos) = malloc(sizeof(char *) * 5);
    for (int size = 0; i < 4; size++, i++, j = 0) {
        (*pos)[i] = malloc(sizeof(char) * (my_strlen(buff)));
        while (buff[size] != '\n') {
            (*pos)[i][j] = buff[size];
            j++;
            size++;
        }
        (*pos)[i][j] = '\0';
    }
    (*pos)[i] = NULL;
}

char **create_map(char **map)
{
    int p = 2;

    map = malloc(sizeof(char *) * 9);
    for (int i = 0; i != 8; i++, p = 2) {
        map[i] = malloc(sizeof(char) * 19);
        map[i][0] = (i + 1) + '0';
        map[i][1] = '|';
        while (p < 17) {
            map[i][p] = '.';
            p++;
            map[i][p] = ' ';
            p++;
            map[i][p] = '\0';
        }
    }
    map[8] = NULL;
    return map;
}

char *read_file(char *file)
{
    int fd = 0;
    int result = 0;
    char *buff = malloc(sizeof(char) * 33);

    fd = open(file, O_RDONLY);
    result = read(fd, buff, 32);
    buff[32] = '\0';
    return buff;
}