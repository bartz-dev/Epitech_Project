/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int result = 0;

    while (s1[i] != '\0' &&  s2[j] != '\0') {
        if (s1[i] != s2[j]) {
            result = (s1[i] - s2[j]);
            return (result);
        }
        i = i + 1;
        j = j + 1;
    }
}
