/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** error_handling.c
*/

#include "navy.h"

int check_positions(char *buff)
{
    char **pos = NULL;

    if (getnbrlinepos(buff) == 1 || getnbrcolpos(buff) == 1)
        return 1;
    save_pos(buff, &pos);
    free(buff);
    if (check_strpos(pos) == 1)
        return 1;
    if (check_collision(pos) == 1) {
        my_free_tab(pos);
        return 1;
    }
    my_free_tab(pos);
}

int check_filepos(char *file)
{
    int fd = 0;
    int result = 0;
    char *buff = malloc(sizeof(char) * 33);

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return 1;
    result = read(fd, buff, 33);
    if (result == -1 || result != 32) {
        free(buff);
        return 1;
    }
    buff[32] = '\0';
    if (check_positions(buff) == 1)
        return 1;
    return 0;
}

int check_player1(char *file)
{
    if (check_filepos(file) == 1)
        return 1;
    return 0;
}

int check_player2(char *file)
{
    if (check_filepos(file) == 1)
        return 1;
    return 0;
}

int check_error(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 1;
    if (ac == 2 && check_player1(av[1]) == 1)
        return 1;
    if (ac == 3 && check_player2(av[2]) == 1)
        return 1;
    return 0;
}