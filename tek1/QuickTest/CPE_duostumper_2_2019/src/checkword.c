/*
** EPITECH PROJECT, 2020
** checkword
** File description:
** 
*/

#include "my.h"

int my_strlen(char *arg)
{
    int i = 0;

    while (arg[i] != 0)
        i++;
    i--;
    return i;
}

char *getword()
{
    char *word = NULL;
    size_t t = 0;

    printf("\n>");
    getline(&word, &t, stdin);
    return word;
}
