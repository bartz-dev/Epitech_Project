/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox2
*/

#include "game.h"
#include <stdlib.h>

linked_list_t *scale_hitbox(linked_list_t *hitbox, sfVector2f scale)
{
    linked_list_t *scaled = 0;
    hitbox_t *source_hitbox;
    hitbox_t *scaled_hitbox;

    for (linked_list_t *i = hitbox; i; i = i->next) {
        source_hitbox = i->data;
        scaled_hitbox = malloc(sizeof(hitbox_t));
        scaled_hitbox->type = source_hitbox->type;
        scaled_hitbox->box = scale_float_rect(source_hitbox->box, float_rect(
            scale.x, scale.y, scale.x, scale.y
        ));
        scaled = ll_append(scaled, scaled_hitbox);
    }
    return scaled;
}