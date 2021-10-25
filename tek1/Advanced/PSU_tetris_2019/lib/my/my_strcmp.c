/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] == s2[i]; i++)
        if (s1[i] == '\0' && s2[i] == '\0')
            return (1);
    return (0);
}
