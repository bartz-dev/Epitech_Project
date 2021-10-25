/*
** EPITECH PROJECT, 2019
** Getnextline
** File description:
** get_next_line.c
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(const int fd)
{
    static char path[READ_SIZE];
    static char *lin = NULL;
    static int end = 1;
    static int cols = 0;
    static int line = 0;
    static int len = 0;

    if (path[cols] == '\0') {
        if ((len = read(fd, path, READ_SIZE)) <= 0)
            return (lin = (((len == -1) || (cols != 0 && path[cols - 1] =='\n')
            || !(path[cols] == '\0' && end--)) ? NULL : lin));
        path[len] = ((cols = 0) ? '\0' : 0);
    }
    if ((lin = ((line == 0) ? malloc((READ_SIZE + 1))
    : realloc(lin, (READ_SIZE + line + 1)))) == NULL)
        return (NULL);
    while (path[cols] && path[cols] != '\n')
        lin[line++] = path[cols++];
    lin[line] = '\0';
    if (path[cols] == '\n')
        return (((line = (cols++ * 0))) ? (NULL) : (lin));
    return (get_next_line(fd));
}

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return i;
}