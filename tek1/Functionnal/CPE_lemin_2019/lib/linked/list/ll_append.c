/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"
#include <stdlib.h>

linked_list_t *ll_append(linked_list_t *list, void *value)
{
    linked_list_t *iterator = list;
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    new_element->data = value;
    new_element->next = 0;
    if (!iterator) return new_element;
    while (iterator->next) iterator = iterator->next;
    iterator->next = new_element;
    return list;
}