/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2019
** File description:
** main.c
*/

#include "ls.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **argv)
{
    int i = 1;
    ls_t *ls = {0};

    ls = malloc(sizeof(ls_t));
    ls->ac = ac;
    if (ac == 1)
        my_ls(".", ls);
    else {
        while (i != ac) {
            ls->dir = 0;
            checkarg(argv[i], ls);
            ls->i = i;
            ls->dir != 1 ? i = i : my_ls(ls->arg, ls);
            i++;
        }
        ls->dir == 0 && ls->checkend == 0 ? my_ls(".", ls) : i--;
    }
    return 0;
}
