/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start
*/

#include "rpg.h"

void start_fight(dialogue_t **dial, dictionary_t **gamedata,
    dictionary_t **entities)
{
    static int dialogue_trigger = 0;
    entity_t *player = dict_get(*entities, "player");

    if (*dial && !my_strcmp((*dial)->progress->part->name, "fight"))
        dialogue_trigger = 1;
    if (!(*dial) && dialogue_trigger) {
        dialogue_trigger = 0;
        if (player)
            player->show = 0;
        import_map("combat.map", entities, gamedata);
    }
}