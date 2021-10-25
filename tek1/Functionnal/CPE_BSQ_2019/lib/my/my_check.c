/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** checking tab x,y
*/

#include <stdio.h>
#include "struct.h"
#include "my.h"

void tabtab(char **tab, int x, int y, int count)
{
    int	i;
    int	save;
    int	a;

    a = 0;
    save = count - 1;
    i = count - 1;
    while (i > 0) {
        while (save > 0) {
            tab[x][y - a] = 'x';
            a = a + 1;
            save = save - 1;
	    }
        save = count - 1;
        a = 0;
        x = x - 1;
        i = i - 1;
    }
}

void my_search2(char **tab, int *lenght, int *width, t_bsq *bsq)
{
    bsq->tmpwidth = *width;
    bsq->tmplenght = *lenght;
    bsq->tmp = 1;
    while (*lenght >= 0 && *width >= 0 && test_tab(bsq->tmp, tab, *width,
                                                            *lenght) == 1) {
        *lenght = *lenght - 1;
        *width = *width - 1;
        bsq->tmp = bsq->tmp + 1;
    }
    if (bsq->tmp >= bsq->count) {
        bsq->count = bsq->tmp;
        bsq->x = *lenght + bsq->count - 1;
        bsq->y = *width + bsq->count - 1;
    }
    *width = bsq->tmpwidth;
    *lenght = bsq->tmplenght;
    *width = *width - 1;
}

void find(char **tab, int *lenght, int *width, t_bsq *bsq)
{
    if (tab[*lenght][*width] == 'o' && *width != 0)
        *width = *width - 1;
    else if (*width == 0) {
        *lenght = *lenght - 1;
        *width = bsq->wid;
    }
    if (tab[*lenght][*width] == '.')
        my_search2(tab, lenght, width, bsq);
    bsq->i = bsq->i + 1;
}

int tabtab2(char **tab)
{
    int	a;
    int	b;

    a = 0;
    b = 0;
    while (tab[a][b] != 0) {
        if (tab[a][b] == '.') {
            tab[a][b] = 'x';
            return (0);
	    }
        else if (tab[a][b] == 'o')
            b = b + 1;
        else {
            b = 0;
            a = a + 1;
	    }   
    }
    return (0);
}
