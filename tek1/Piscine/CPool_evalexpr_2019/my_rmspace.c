/*
** EPITECH PROJECT, 2019
** eval_expr-master
** File description:
** my_rmspace.c
*/

#include <stdlib.h>

char *suppr_spaces(char *str)
{
    int i;
    int j;
    char *str2;

    i = 0;
    j = 0;
    str2 = malloc(my_strlen(str) + 1);
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str2[j] = str[i];
            j = j + 1;
	}
        i = i + 1;
    }
    str2[j] = '\0';
    return (str2);
}
