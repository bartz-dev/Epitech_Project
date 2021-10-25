/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** 
*/

#include "my.h"

void writeline_p(int size)
{
    int count = 0;
    
    while (count != size*2+3) {
        printf("%c", '+');
        count++;
    }
}

int launchbasic(char **av, int size)
{
    int count = 0;
    int i;
    if (av[1][0] == '-' && av[1][1] == 'g') {
        writeline_p(size);
        count = 0;
        for (int p = 0; p != size; p++) {
            printf("\n| ");
            for (i = 0; i != size; i++, count++) {
                printf("%c ", av[2][count]);
            }
            i = 0;
            printf("|");
        }
        printf("\n");
        writeline_p(size);
    }
}
