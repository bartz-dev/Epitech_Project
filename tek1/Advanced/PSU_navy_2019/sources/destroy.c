/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** destroy.c
*/

#include "navy.h"

void my_free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}