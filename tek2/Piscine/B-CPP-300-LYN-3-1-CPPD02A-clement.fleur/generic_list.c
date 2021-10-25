/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-clement.fleur
** File description:
** generic_list.c
*/

#include "generic_list.h"
#include <stddef.h>

node_t *create_node_generic(void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    node->value = elem;
    node->next = NULL;

    return node;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    while (list) {
        val_disp(list->value);
        list = list->next;
    }
}

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = create_node_generic(elem);

    if (!node)
        return false;
    node->next = *front_ptr;
    *front_ptr = node;

    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *node = create_node_generic(elem);
    list_t list = *front_ptr;

    if (!node)
        return false;
    if (!list)
        *front_ptr = node;
    else {
        list = *front_ptr;
        while (list->next)
            list = list->next;
        list->next = node;
    }

    return true;
}

bool list_add_elem_at_position (list_t *front_ptr, void *elem,
unsigned int position)
{
    node_t *node = create_node_generic(elem);
    list_t linked_list = *front_ptr;

    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    if (!node)
        return false;
    if (!*front_ptr)
        return false;
    while (position--) {
        linked_list = linked_list->next;
        if (!linked_list)
            return false;
    }
    node->next = linked_list->next;
    linked_list->next = node;

    return true;
}