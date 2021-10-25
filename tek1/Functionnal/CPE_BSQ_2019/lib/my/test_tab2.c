/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** testing string and redirecting
*/

#include <stdio.h>
#include "struct.h"
#include "my.h"

void redirect(char **tab, int lenght, int width)
{
    t_bsq bsq;

    bsq.len = lenght;
    bsq.wid = width;
    bsq.count = 0;
    bsq.tmp = 0;
    bsq.i = 0;
    while (bsq.i < (bsq.len + 1) * (bsq.wid + 1))
        find(tab, &lenght, &width, &bsq);
    if (bsq.count > 2)
        tabtab(tab, bsq.x, bsq.y, bsq.count);
    else
        tabtab2(tab);
    bsq.i = 0;
    while (bsq.i <= bsq.len) {
        my_putstr(tab[bsq.i]);
        my_putchar('\n');
        bsq.i = bsq.i + 1;
    }
}

int test_tab(int tmp, char **tab, int width, int lenght)
{
    int	i = 0;

    if (tab[lenght][width] != '.')
        return (0);
    while (i < tmp) {
        if (tab[lenght][width + i] != '.'  || tab[lenght + i][width] != '.')
            return (0);
        i = i + 1;
    }
    return (1);
}
