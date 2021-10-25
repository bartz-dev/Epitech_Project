/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** char * to char ** by clément Fleur
*/

#include <stdlib.h>
#include "my.h"

char **my_stringtotab(char *str,char **tab, int x, int y)
{
    int i = 0;

    while (str[i] !=  '\n' && str[i] != '\0')
        i = i + 1;
    i++;
    while (str[i] != '\0') {
        if (str[i] == '\n' || str[i] == '\0') {
            tab[x][y] = '\0';
            x = x + 1;
            y = 0;
        }
        else {
            tab[x][y] = str[i];
            y = y + 1;
        }
        i = i + 1;
    }
}

char **my_strtodouble(char *str, int size)
{
    char **new_str;
    int i = 0;

    new_str = malloc(sizeof(*new_str) * my_strlen_nbligne(str) + 1);
    if (new_str == NULL)
        my_putstr("error");
    while (i < my_strlen_nbligne(str)) {
        new_str[i] = malloc(sizeof(char) * my_strlenbn(str) + 1);
        i = i + 1;
    }
    my_stringtotab(str, new_str, 0, 0);
    redirect(new_str, my_strnbline(str) - 1, my_strlenbn(str) - 1);
} 