/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** my_strncmp
*/

#include <stdlib.h>
#include "tools.h"

int my_strncmp(char *s1, char *s2, int n)
{
    char *new_s1 = my_strdup(s1);
    char *new_s2 = my_strdup(s2);
    int return_value;

    if (my_strlen(new_s1) >= n)
        new_s1[n] = 0;
    if (my_strlen(new_s2) >= n)
        new_s2[n] = 0;
    return_value = my_strcmp(new_s1, new_s2);
    free(new_s1);
    free(new_s2);
    return return_value;
}