/*
** EPITECH PROJECT, 2019
** Bootstrap_BSQ
** File description:
** open file by clement Fleur
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"

int open_file(char *str)
{
    int fd;
    int len;
    int size;
    struct stat byte;

    fd = open(str, O_RDONLY);
    stat(str, &byte);
    if (byte.st_size == 0) {
        my_putstr("error");
        return 84;
    }
    str = malloc(sizeof(char) * (byte.st_size + 1));
    size = read(fd, str, byte.st_size);
    str[byte.st_size - 1] = 0; // ajoute \0 fin de read
    my_strtodouble(str, byte.st_size);
    close(fd);
}