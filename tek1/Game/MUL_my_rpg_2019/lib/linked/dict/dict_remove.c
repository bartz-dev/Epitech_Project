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
    dictionary_t *iterator = dict;
    dictionary_t *temp = dict;
    dictionary_t *prev = 0;

    while (iterator) {
        if (!my_strcmp(iterator->index, index) && !prev) {
            temp = iterator->next;
            return temp->next;
        } else {
            prev->next = iterator->next;
        }
        prev = iterator;
        iterator = iterator->next;
    }
    return temp;
}