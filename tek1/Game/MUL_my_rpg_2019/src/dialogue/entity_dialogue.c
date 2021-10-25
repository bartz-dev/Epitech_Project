/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** entity_dialogue
*/

#include "rpg.h"
#include <stdlib.h>

linked_list_t *dialogue_load_conditions(json_object_t *obj)
{
    linked_list_t *conditions = 0;
    dialogue_condition_t *cond;
    char *str;
    double *value;

    for (json_object_t *i = obj; i; i = i->next) {
        cond = malloc(sizeof(dialogue_condition_t));
        cond->type = my_strdup(dict_get(i->data, "type"));
        str = dict_get(i->data, "quest");
        cond->quest = str ? my_strdup(str) : 0;
        str = dict_get(i->data, "condition");
        cond->condition = str ? my_strdup(str) : 0;
        value = dict_get(i->data, "value");
        cond->value = value ? *value : 0;
        conditions = ll_append(conditions, cond);
    }
    return conditions;
}

dictionary_t *entity_load_dialogues(char *name, json_object_t *obj)
{
    dictionary_t *dialogues = 0;
    linked_list_t *conditions;
    dialogue_t *dial;

    for (json_object_t *i = obj; i; i = i->next) {
        conditions = dialogue_load_conditions(dict_get(i->data, "conditions"));
        dial = import_dialogue(dict_get(i->data, "file"));
        dial->conditions = conditions;
        dial->npc = my_strdup(name);
        dialogues = dict_add(dialogues, my_strdup(dict_get(i->data, "file")),
            dial);
    }
    return dialogues;
}