/*
** EPITECH PROJECT, 2020
** libgame
** File description:
** entity2
*/

#include "game.h"
#include <stdlib.h>

dictionary_t *imp_add_anim(dictionary_t *animations, sfSprite *sprite,
    animation_t *a, char *name)
{
    a->sprite = sprite;
    animations = dict_add(animations, name, a);
    return animations;
}

double entity_distance(entity_t *a, entity_t *b)
{
    return distance(sfSprite_getPosition(a->sprite),
        sfSprite_getPosition(b->sprite));
}

void parse_hitbox(entity_t *e, linked_list_t *obj)
{
    hitbox_t *hitbox;
    sfFloatRect box;
    sfIntRect size = sfSprite_getTextureRect(e->sprite);

    for (linked_list_t *i = obj; i; i = i->next) {
        hitbox = malloc(sizeof(hitbox_t));
        box = float_rect_from_ll(dict_get(i->data, "rect"));
        box.left *= size.width;
        box.width *= size.width;
        box.top *= size.height;
        box.height *= size.height;
        hitbox->entity = e;
        hitbox->box = box;
        hitbox->type = hitbox_type(dict_get(i->data, "type"));
        e->hitbox = ll_append(e->hitbox, hitbox);
    }
}

linked_list_t *check_all_collisions(entity_t *e, char *name,
    dictionary_t *entities, linked_list_t *layers)
{
    linked_list_t *collisions = 0;

    for (dictionary_t *i = entities; i; i = i->next) {
        if (my_strcmp(i->index, name))
            collisions = ll_concat(collisions, check_entity_coll(e, i->data));
    }
    for (linked_list_t *i = layers; i; i = i->next)
        collisions = ll_concat(collisions, check_layer_collision(e, i->data));
    return collisions;
}
