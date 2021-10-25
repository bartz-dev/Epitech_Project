/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** dict_get
*/

#include "tools.h"
#include "linked.h"

void *dict_get(dictionary_t *dict, char *index)
{
    dictionary_t *iterator = dict;

    while (iterator) {
        if (!my_strcmp(iterator->index, index)) {
            return iterator->data;
        }
        iterator = iterator->next;
    }
    return 0;
}

dictionary_t *dict_set(dictionary_t *dict, char *index, void *value)
{
    dictionary_t *iterator = dict;

    while (iterator) {
        if (!my_strcmp(iterator->index, index)) {
            iterator->data = value;
            return dict;
        }
        iterator = iterator->next;
    }
    return dict_add(dict, index, value);
}