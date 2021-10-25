/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** no_flag.c
*/

#include "my.h"
#include "ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

void no_flag(char *directory)
{
    DIR *rep = opendir(directory);
    struct dirent *read;
    int i = 1;

    while ((read = readdir(rep)) != NULL) {
        if (read->d_name[0] != '.') {
            my_putstr(read->d_name);
            my_putstr("  ");
        }
    }
}