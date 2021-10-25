/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** check.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "ls.h"

void checkdescription(char *arg, ls_t *ls)
{
    int i = 1;
    while (arg[i]) {
        switch (arg[i]) {
        case 'l':
            ls->l = 1;
            break;
        case 'r':
            ls->r = 1;
            break;
        case 't':
            ls->t = 1;
            break;
        default:
            my_putstr("Wrong description: only -l, -r, -t");
            exit(84);
            break;
        }
        i++;
    }
}

int check_path(char *arg, ls_t *ls)
{
    if (arg[0] != '-') {
        ls->dir = 1;
        ls->checkend++;
        return 1;
    }
    else {
        checkdescription(arg, ls);
        return 0;
    }
}

char *checkarg(char *argv, ls_t *ls)
{
    int checker = check_path(argv, ls);

    if (checker == 1) {
        ls->arg = malloc(sizeof(char) * my_strlen(argv + 2));
        ls->arg = argv;
        ls->arg[my_strlen(argv)] = 0;
    }
    return ".";
}