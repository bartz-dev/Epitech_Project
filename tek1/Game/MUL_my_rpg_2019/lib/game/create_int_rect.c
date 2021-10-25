/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** create_int_rect
*/

#include "game.h"

sfFloatRect float_rect_from_ll(linked_list_t *list)
{
    if (ll_len(list) < 4) return float_rect(0, 0, 0, 0);
    return float_rect(*(double *) ll_get(list, 0),
        *(double *) ll_get(list, 1), *(double *) ll_get(list, 2),
        *(double *) ll_get(list, 3));
}

sfIntRect int_rect_from_ll(linked_list_t *list)
{
    if (ll_len(list) < 4) return create_int_rect(0, 0, 0, 0);
    return create_int_rect(*(int *) ll_get(list, 0), *(int *) ll_get(list, 1),
        *(int *) ll_get(list, 2), *(int *) ll_get(list, 3));
}

sfIntRect create_int_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return rect;
}

sfFloatRect float_rect(float left, float top, float width, float height)
{
    sfFloatRect rect;

    rect.left = left;
    rect.top = top;
    rect.width = width;
    rect.height = height;
    return rect;
}

sfFloatRect scale_float_rect(sfFloatRect rect, sfFloatRect scale)
{
    return float_rect(rect.left * scale.left, rect.top * scale.top,
        rect.width * scale.width, rect.height * scale.height);
}