/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-clement.fleur
** File description:
** get_generic_list.c
*/

#include "generic_list.h"
#include <stddef.h>

unsigned int list_get_size(list_t list)
{
    int size = 0;

    while (list) {
        size++;
        list = list->next;
    }

    return size;
}

node_t *list_get_first_node_with_value(list_t list, void *value,
    value_comparator_t val_comp)
{
    while (list) {
        if (!val_comp(value, list->value))
            return list;
        list = list->next;
    }
    return NULL;
}

void *list_get_elem_at_position(list_t list,
unsigned int position)
{
    if (position == 0)
        return list_get_elem_at_front(list);
    if (!list)
        return (0);
    for (unsigned int i = 0; i < position; i++) {
        if (!list)
            return 0;
        list = list->next;
    }
    return (list->value);
}

void *list_get_elem_at_front(list_t list)
{
    if (!list) {
        return 0;
    }
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (!list)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}