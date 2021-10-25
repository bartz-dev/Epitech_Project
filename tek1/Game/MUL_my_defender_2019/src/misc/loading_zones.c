/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** loading_zones
*/

#include "rpg.h"

void check_loading_zones(dictionary_t **entities, dictionary_t **gamedata)
{
    entity_t *l_zone;
    entity_t *player;
    linked_list_t *collisions;
    sfVector2f pos;

    for (dictionary_t *i = *entities; i; i = i->next) {
        if (!my_str_startswith(i->index, "load_zone")) continue;
        l_zone = i->data;
        collisions = check_all_collisions(l_zone, i->index, *entities, 0);
        if (check_collision_type(collisions, HITBOX_PLAYER)) {
            player = dict_get(*entities,
                dict_get(l_zone->extra_data, "entity"));
            pos = sv2f(*(double *) dict_get(l_zone->extra_data, "pos_x"),
                *(double *) dict_get(l_zone->extra_data, "pos_y"));
            sfSprite_setPosition(player->sprite, pos);
            import_map(dict_get(l_zone->extra_data, "map"), entities, gamedata);
            return;
        }
    }
}