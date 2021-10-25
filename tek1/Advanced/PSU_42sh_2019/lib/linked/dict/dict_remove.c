/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** dict_remove
*/

#include "tools.h"
#include "linked.h"
#include <stdlib.h>

dictionary_t *dict_remove(dictionary_t *dict, char *index)
{
    dictionary_t *temp = dict;
    dictionary_t *prev = 0;

    for (dictionary_t *iterator = dict; iterator; iterator = iterator->next) {
        if (!my_strcmp(iterator->index, index) && !prev) {
            temp = iterator->next;
            free(iterator);
            return temp;
        } else if (!my_strcmp(iterator->index, index)) {
            prev->next = iterator->next;
            free(iterator);
            return dict;
        }
        prev = iterator;
    }
    return temp;
}