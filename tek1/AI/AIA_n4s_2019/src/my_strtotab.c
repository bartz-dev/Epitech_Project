/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** my_strtotab.c
*/

#include "n4s.h"

char **my_strtotab(char *str, char lim)
{
    char **tab = malloc(sizeof(char **) * my_strlen(str));
    int i = 0;
    int j = 0;
    int k;

    if (tab == NULL)
        return (NULL);
    while (str[i] != 0) {
        k = 0;
        if ((tab[j] = malloc(sizeof(char *) * my_strlen(str))) == NULL)
            return (NULL);
        while (str[i] == lim && str[i++] != 0);
        while (str[i] != lim && str[i] != 0)
            tab[j][k++] = str[i++];
        tab[j++][k] = 0;
        while (str[i] == lim && str[i++] != 0);
    }
    tab[j] = NULL;
    return (tab);
}
