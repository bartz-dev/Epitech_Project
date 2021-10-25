/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** dialogues
*/

#include "rpg.h"
#include <stdlib.h>

reward_t *import_reward(json_object_t *obj)
{
    reward_t *reward = malloc(sizeof(reward_t));
    char *item = dict_get((dictionary_t *) obj, "item");

    reward->type = my_strdup(dict_get((dictionary_t *) obj, "type"));
    reward->item = item ? my_strdup(item) : 0;
    reward->value = *(int *) dict_get((dictionary_t *) obj, "value");
    return reward;
}

dialogue_choice_t *import_dialogue_choice(json_object_t *obj)
{
    dialogue_choice_t *choice = malloc(sizeof(dialogue_choice_t));

    choice->text = my_strdup(dict_get((dictionary_t *) obj, "text"));
    choice->go_to = my_strdup(dict_get((dictionary_t *) obj, "goto"));
    return choice;
}

dialogue_line_t *import_dialogue_line(json_object_t *obj)
{
    dialogue_line_t *line = malloc(sizeof(dialogue_line_t));

    line->name = my_strdup(dict_get((dictionary_t *) obj, "name"));
    line->text = my_strdup(dict_get((dictionary_t *) obj, "text"));
    line->choices = 0;
    for (json_object_t *i = dict_get((dictionary_t *) obj, "choices"); i;
        i = i->next)
        line->choices = ll_append(line->choices,
            import_dialogue_choice(i->data));
    return line;
}

dialogue_part_t *import_dialogue_part(char *name, json_object_t *obj)
{
    dialogue_part_t *part = malloc(sizeof(dialogue_part_t));

    part->lines = 0;
    part->quests = 0;
    part->rewards = 0;
    part->name = my_strdup(name);
    for (json_object_t *i = dict_get((dictionary_t *) obj, "lines"); i;
        i = i->next)
        part->lines = ll_append(part->lines, import_dialogue_line(i->data));
    for (json_object_t *i = dict_get((dictionary_t *) obj, "rewards"); i;
        i = i->next)
        part->rewards = ll_append(part->rewards, import_reward(i->data));
    for (json_object_t *i = dict_get((dictionary_t *) obj, "quests"); i;
        i = i->next)
        part->quests = ll_append(part->quests, my_strdup(i->data));
    return part;
}

dialogue_t *import_dialogue(char *filename)
{
    dialogue_t *dialogue = malloc(sizeof(dialogue_t));
    char *path = my_strconcat("./assets/dialogues/", filename);
    json_object_t *obj = my_free_assign(path, read_json(path));

    dialogue->default_part = my_strdup(dict_get(obj->data, "default"));
    dialogue->parts = 0;
    for (json_object_t *i = obj->data; i; i = i->next) {
        if (!my_strcmp(i->index, "default")) continue;
        dialogue->parts = dict_add(dialogue->parts, my_strdup(i->index),
            import_dialogue_part(i->index, i->data));
    }
    dialogue->progress = malloc(sizeof(dialogue_progress_t));
    dialogue->progress->part = dict_get(dialogue->parts,
        dialogue->default_part);
    dialogue->progress->line = 0;
    json_destroy(obj);
    return dialogue;
}