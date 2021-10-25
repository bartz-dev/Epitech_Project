/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** entity3
*/

#include "rpg.h"

dictionary_t *sort_entities_step(dictionary_t *entities, int *must_continue)
{
    entity_t *e1;
    entity_t *e2;

    for (int i = 0; i < dict_len(entities) - 1; i++) {
        e1 = ll_get((linked_list_t *) entities, i);
        e2 = ll_get((linked_list_t *) entities, i + 1);
        if (sfSprite_getPosition(e1->sprite).y >
            sfSprite_getPosition(e2->sprite).y) {
            entities = dict_swap(entities, i, i + 1);
            *must_continue = 1;
        }
    }
    return entities;
}

dictionary_t *sort_entities(dictionary_t *entities)
{
    int must_continue = 1;

    while (must_continue) {
        must_continue = 0;
        entities = sort_entities_step(entities, &must_continue);
    }
    return entities;
}