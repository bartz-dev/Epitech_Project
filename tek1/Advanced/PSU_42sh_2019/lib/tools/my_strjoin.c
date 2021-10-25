/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** my_strjoin
*/

#include "tools.h"

char *my_strjoin(char **arr, char *glue)
{
    char *final = my_strdup("");
    int first = 1;

    for (int i = 0; arr[i]; i++) {
        if (!first)
            final = my_free_assign(final,
                my_strconcat(final, glue));
        final = my_free_assign(final, my_strconcat(final, arr[i]));
        first = 0;
    }
    return final;
}