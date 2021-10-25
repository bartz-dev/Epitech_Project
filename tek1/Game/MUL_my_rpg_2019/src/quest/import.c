/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** quest import
*/

#include "rpg.h"
#include <stdlib.h>

linked_list_t *quest_import_rewards(json_object_t *obj)
{
    linked_list_t *rewards = 0;

    for (json_object_t *i = obj; i; i = i->next) {
        rewards = ll_append(rewards, import_reward(i->data));
    }
    return rewards;
}

objective_t *import_objective(json_object_t *obj)
{
    objective_t *objective = malloc(sizeof(objective_t));

    objective->instruction = my_strdup(
        dict_get((dictionary_t *) obj, "instruction"));
    objective->type = my_strdup(dict_get((dictionary_t *) obj, "type"));
    objective->target = my_strdup(dict_get((dictionary_t *) obj, "target"));
    objective->nb_required = *(int *)
        dict_get((dictionary_t *) obj, "nb_required");
    objective->progress = 0;
    objective->rewards = quest_import_rewards(
        dict_get((dictionary_t *) obj, "rewards"));
    return objective;
}

dictionary_t *import_objectives(json_object_t *obj)
{
    dictionary_t *objectives = 0;

    for (json_object_t *i = obj; i; i = i->next) {
        objectives = dict_add(objectives,
            my_strdup(dict_get(i->data, "name")), import_objective(i->data));
    }
    return objectives;
}

quest_t *import_quest(char *filename)
{
    char *path = my_strconcat("./assets/quests/", filename);
    json_object_t *obj = my_free_assign(path, read_json(path));
    quest_t *quest = malloc(sizeof(quest_t));

    quest->name = my_strdup(dict_get(obj->data, "name"));
    quest->redeem_to = my_strdup(dict_get(obj->data, "redeem_to"));
    quest->objectives = import_objectives(dict_get(obj->data, "objectives"));
    quest->objective = quest->objectives ?
        my_strdup(quest->objectives->index) : 0;
    quest->given_by = 0;
    quest->rewards = quest_import_rewards(dict_get(obj->data, "rewards"));
    json_destroy(obj);
    return quest;
}