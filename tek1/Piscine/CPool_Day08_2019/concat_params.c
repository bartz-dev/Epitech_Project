/*
** EPITECH PROJECT, 2019
** concat_params
** File description:
** concat_params by clement fleur
*/

#include "my.h"
#include <stdlib.h>

int length(int argc, char **argv, int p)
{
    int count2;
    int i = 0;

    count2 = 0;
    while (i < argc)
    {
        while (argv[i][count2] != '\0') {
            count2++;
            p++;
        }
        i++;
        p++;
    }
    return p;
}

char *concat_params(int argc, char **argv)
{
    char *str;
    int i = 0;
    int p = 0;
    int count;

    count = 0;
    length(argc, argv, p);
    str = malloc(sizeof(char) * p);
    while (i < argc) {
        for (int check = 0; argv[i][check] != '\0'; check++) {
            str[count] = argv[i][check];
            count++;
        }
        i++;
        if (i < argc) {
            str[count] = '\n';
            count++;
        }
    }
    return str;
}
