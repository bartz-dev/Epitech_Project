/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** start
*/

#include "rpg.h"

int check_dial_condition(dialogue_condition_t *cond, quest_t *quest)
{
    char **split;

    if (!my_strcmp(cond->quest, "none") && !quest)
        return 1;
    split = my_strsplit(cond->quest, ':');
    if (!my_strcmp(split[0], quest->file) &&
        !my_strcmp(split[1], quest->objective)) {
        free(split[0]);
        free(split);
        return 1;
    }
    free(split[0]);
    free(split);
    return 0;
}

int check_dial_conditions(linked_list_t *conditions, quest_t *quest)
{
    int cond_ok = 1;

    for (linked_list_t *i = conditions; i; i = i->next)
        cond_ok = cond_ok ? check_dial_condition(i->data, quest) : 0;
    return cond_ok;
}

dialogue_t *dialogue_start(entity_t *entity, quest_t *quest)
{
    linked_list_t *dialogues = dict_get(entity->extra_data, "dialogues");
    dialogue_t *dial;

    for (linked_list_t *i = dialogues; i; i = i->next) {
        dial = i->data;
        if (check_dial_conditions(dial->conditions, quest))
            return dial;
    }
    return 0;
}