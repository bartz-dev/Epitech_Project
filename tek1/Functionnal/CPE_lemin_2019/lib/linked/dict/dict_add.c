/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** dict_add
*/

#include "tools.h"
#include "linked.h"
#include <stdlib.h>

dictionary_t *dict_add(dictionary_t *dict, char *index, void *value)
{
    dictionary_t *iterator = dict;
    dictionary_t *new_element = malloc(sizeof(dictionary_t));

    new_element->index = index;
    new_element->data = value;
    new_element->next = 0;
    if (!iterator) return new_element;
    while (iterator->next) iterator = iterator->next;
    iterator->next = new_element;
    return dict;
}

dictionary_t *dict_add_before(dictionary_t *dict, char *key, void *value,
    char *before)
{
    dictionary_t *iterator = dict;
    dictionary_t *new_element = malloc(sizeof(dictionary_t));
    dictionary_t *prev = 0;

    new_element->index = key;
    new_element->data = value;
    while (iterator) {
        if (!my_strcmp(iterator->index, before) && !prev) {
            new_element->next = iterator;
            return new_element;
        } else if (!my_strcmp(iterator->index, before)) {
            prev->next = new_element;
            new_element->next = iterator;
            return dict;
        }
        iterator = iterator->next;
    }
    return dict;
}

dictionary_t *dict_add_after(dictionary_t *dict, char *key, void *value,
    char *after)
{
    dictionary_t *iterator = dict;
    dictionary_t *new_element = malloc(sizeof(dictionary_t));

    new_element->index = key;
    new_element->data = value;
    while (iterator) {
        if (!my_strcmp(iterator->index, after)) {
            new_element->next = iterator->next;
            iterator->next = new_element;
            return dict;
        }
        iterator = iterator->next;
    }
    return dict;
}