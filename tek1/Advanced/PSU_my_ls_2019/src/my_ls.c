/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** my_ls.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "ls.h"

void redirect(char *directory, ls_t *ls)
{
    if (ls->ac > 3) {
        my_putstr(directory);
        my_putstr(":\n");
    }
    if (ls->l == 1)
        l_flag(directory);
    if (ls->l == 0 && ls->r == 0 && ls->t == 0)
        no_flag(directory);
    if ((ls->i) < ls->ac)
        my_putstr("\n");
}

int my_ls(char *directory, ls_t *ls)
{
    DIR *rep = opendir(directory);
    struct dirent *lecture;
    ls->count = 0;

    if (rep == NULL) {
        my_putstr("error you have enterred a wrong folder name for : ");
        my_putstr(directory);
        exit(84);
    }
    redirect(directory, ls);
    closedir(rep);
}