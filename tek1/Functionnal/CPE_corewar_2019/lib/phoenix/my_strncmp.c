/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d02_2019
** File description:
** my_strncmp.c
*/

#include "phoenix.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i != n; i++) {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
    }

    if (my_strlen(s1) < n)
        return (-1);
    else if (my_strlen(s2) < n)
        return (1);
    else
        return (0);
}