/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** sf_vectors
*/

#include "game.h"

sfVector2i sv2i(int x, int y)
{
    sfVector2i v;

    v.x = x;
    v.y = y;
    return v;
}

sfVector2f sv2f(float x, float y)
{
    sfVector2f v;

    v.x = x;
    v.y = y;
    return v;
}

sfVector3f sv3f(float x, float y, float z)
{
    sfVector3f v;

    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

sfVector2f sv2f_from_ll(linked_list_t *list)
{
    sfVector2f vector = sv2f(*(double *) ll_get(list, 0),
        *(double *) ll_get(list, 1));

    return vector;
}