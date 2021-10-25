/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"

void *ll_get(linked_list_t *list, int index)
{
    linked_list_t *iterator = list;
    int i = 0;

    while (iterator) {
        if (i == index) return iterator->data;
        i++;
        iterator = iterator->next;
    }
    return 0;
}

void ll_set(linked_list_t *list, int index, void *value)
{
    linked_list_t *iterator = list;
    int i = 0;

    while (iterator) {
        if (i == index) {
            iterator->data = value;
            return;
        }
        i++;
        iterator = iterator->next;
    }
}