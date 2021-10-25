/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** progress
*/

#include "rpg.h"

char *get_next_objective(dictionary_t *objectives, char *current)
{
    int next = 0;

    for (dictionary_t *i = objectives; i; i = i->next) {
        if (next)
            return i->index;
        if (!my_strcmp(i->index, current))
            next = 1;
    }
    return 0;
}

quest_t *quest_progress(quest_t *quest, char *progress_type, char *target,
    int amount)
{
    char *obj_name;
    objective_t *obj;

    if (!quest) return 0;
    obj_name = quest->objective;
    obj = obj_name ? dict_get(quest->objectives, obj_name) : 0;
    if (!obj) return 0;
    if (!my_strcmp(obj->type, progress_type) && !my_strcmp(obj->target,
        target)) {
        obj->progress += amount;
    }
    if (obj->progress >= obj->nb_required) {
        obj->progress = 0;
        quest->objective = get_next_objective(quest->objectives,
            quest->objective);
        if (!quest->objective)
            return 0;
    }
    return quest;
}