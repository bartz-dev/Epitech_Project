/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-clement.fleur
** File description:
** tab_to_2dtab.c
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    *res = malloc(sizeof(int *) * length);
    int index = 0;

    for (int p = 0; p != length; p++) {
        (*res)[p] = malloc(sizeof(int) * width);
        for (int i = 0; i < width; i++) {
            (*res)[p][i] = tab[index];
            index++;
        }
    }
}