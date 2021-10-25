/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** free
*/

#include "rpg.h"
#include <stdlib.h>

void reward_free(void *p)
{
    reward_t *reward = p;

    if (reward->item)
        free(reward->item);
    free(reward->type);
    free(reward);
}

void dialogue_choice_free(void *p)
{
    dialogue_choice_t *choice = p;

    free(choice->go_to);
    free(choice->text);
    free(choice);
}

void dialogue_line_free(void *p)
{
    dialogue_line_t *line = p;

    free(line->name);
    free(line->text);
    ll_free(line->choices, dialogue_choice_free);
    free(line);
}

void dialogue_part_free(void *p)
{
    dialogue_part_t *part = p;

    ll_free(part->quests, free);
    ll_free(part->lines, dialogue_line_free);
    ll_free(part->rewards, reward_free);
    free(part);
}

void dialogue_free(dialogue_t *d)
{
    free(d->default_part);
    free(d->progress);
    dict_free(d->parts, 1, dialogue_part_free);
    free(d);
}