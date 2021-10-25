/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** my_free_assign
*/

#include <stdlib.h>

void *my_free_assign(void *to_free, void *value)
{
    free(to_free);
    return value;
}