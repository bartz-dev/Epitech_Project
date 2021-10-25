/*
** EPITECH PROJECT, 2019
** linked_lists
** File description:
** linked_lists
*/

#include "linked.h"
#include <stdlib.h>

linked_list_t *ll_insert(linked_list_t *list, void *value, int index)
{
    linked_list_t *iterator = list;
    linked_list_t *new_list = malloc(sizeof(linked_list_t));
    linked_list_t *temp;
    int i = 0;

    new_list->data = value;
    while (iterator) {
        if (i == index - 1) {
            temp = iterator->next;
            iterator->next = new_list;
            new_list->next = temp;
        }
        i++;
        iterator = iterator->next;
    }
    return list;
}

linked_list_t *ll_add(linked_list_t *list, void *value, int index)
{
    if (index == 0) return ll_prepend(list, value);
    else if (index >= ll_len(list)) return ll_append(list, value);
    else return ll_insert(list, value, index);
}