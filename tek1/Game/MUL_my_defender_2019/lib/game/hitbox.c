/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** hitbox
*/

#include "game.h"
#include <stdlib.h>

int hitbox_type(char *type)
{
    if (!my_strcmp(type, "HITBOX_DAMAGE")) return HITBOX_DAMAGE;
    if (!my_strcmp(type, "HITBOX_WALL")) return HITBOX_WALL;
    if (!my_strcmp(type, "HITBOX_TRIGGER")) return HITBOX_TRIGGER;
    if (!my_strcmp(type, "HITBOX_PLAYER")) return HITBOX_PLAYER;
    return HITBOX_UNKNOWN;
}

sfBool check_box_collision(sfVector2f pos1, sfFloatRect box1,
    sfVector2f pos2, sfFloatRect box2)
{
    box1.left += pos1.x;
    box1.top += pos1.y;
    box2.left += pos2.x;
    box2.top += pos2.y;
    return sfFloatRect_intersects(&box1, &box2, NULL);
}

linked_list_t *check_collision(sfVector2f pos1, linked_list_t *hitbox1,
    sfVector2f pos2, linked_list_t *hitbox2)
{
    collision_t *coll;
    linked_list_t *collisions = 0;
    linked_list_t *i = hitbox1;
    linked_list_t *j = hitbox2;

    while (i && j) {
        if (check_box_collision(pos1, ((hitbox_t *)(i->data))->box, pos2,
            ((hitbox_t *)(j->data))->box)) {
            coll = malloc(sizeof(collision_t));
            coll->box1 = i->data;
            coll->box2 = j->data;
            collisions = ll_append(collisions, coll);
        }
        j = j->next;
        if (!j) {
            j = hitbox2;
            i = i->next;
        }
    }
    return collisions;
}

int check_collision_type(linked_list_t *collisions, int type)
{
    collision_t *coll;

    for (linked_list_t *i = collisions; i; i = i->next) {
        coll = i->data;
        if (coll->box1->type == type || coll->box2->type == type)
            return 1;
    }
    return 0;
}

hitbox_t *get_hitbox(int type, sfFloatRect box)
{
    hitbox_t *hitbox = malloc(sizeof(hitbox_t));

    hitbox->type = type;
    hitbox->box = box;
    return hitbox;
}