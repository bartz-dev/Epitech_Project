/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** dict_destroy
*/

#include "linked.h"
#include <stdlib.h>

void no_free(void *a)
{
    a = a;
}

void dict_destroy_content(dictionary_t *dict)
{
    dictionary_t *iterator = dict;

    while (iterator) {
        free(iterator->data);
        iterator = iterator->next;
    }
}

void dict_destroy(dictionary_t *dict)
{
    if (dict) {
        if (dict->next) dict_destroy(dict->next);
        free(dict);
    }
}

void dict_free(dictionary_t *dict, int free_index, void (free_content)(void *))
{
    if (dict) {
        if (dict->next) dict_free(dict->next, free_index, free_content);
        if (free_index) free(dict->index);
        free_content(dict->data);
        free(dict);
    }
}