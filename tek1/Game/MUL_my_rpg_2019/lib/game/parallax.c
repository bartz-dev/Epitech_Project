/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** parallax
*/

#include "game.h"

void apply_parallax(linked_list_t *layers, sfView *view, sfVector2f *center)
{
    layer_t *layer;
    sfVector2f pos = sfView_getCenter(view);
    sfVector2f corner_pos = {0, 0};
    sfVector2f final_pos = {0, 0};

    corner_pos.x = pos.x - center->x;
    corner_pos.y = pos.y - center->y;
    for (linked_list_t *i = layers; i; i = i->next) {
        layer = i->data;
        final_pos.x = corner_pos.x - corner_pos.x * layer->scroll_speed.x;
        final_pos.y = corner_pos.y - corner_pos.y * layer->scroll_speed.y;
        sfSprite_setPosition(layer->sprite, final_pos);
    }
}