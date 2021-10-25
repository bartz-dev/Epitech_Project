/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** main for sokoban
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "pos.h"

char *read_file(char *path, struct stat byte)
{
    int fd;

    fd = open(path, O_RDWR);
    stat(path, &byte);
    path = malloc(sizeof(char) * (byte.st_size + 1));
    read(fd, path, byte.st_size);
    path[byte.st_size] = 0;
    return path;
}

int main(int ac, char **argv)
{
    char *file;
    struct stat byte;

    check_error(ac, argv);
    file = read_file(argv[1], byte);
    initscr();
    curs_set(0);
    pos_player(file);
    refresh();
    endwin();
    free(file);
    return (0);
}