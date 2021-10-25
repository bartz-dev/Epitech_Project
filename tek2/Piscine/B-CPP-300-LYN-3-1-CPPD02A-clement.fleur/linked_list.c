/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-clement.fleur
** File description:
** linked_list.c
*/

#include "double_list.h"
#include "stddef.h"

doublelist_node_t *create_node_list(double elem)
{
    doublelist_node_t *node = malloc(sizeof(doublelist_node_t));

    node->value = elem;
    node->next = NULL;

    return node;
}

void double_list_dump(double_list_t list)
{
    while (list) {
        printf("%f\n", list->value);
        list = list->next;
    }
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *node = create_node_list(elem);

    if (!node)
        return false;
    node->next = *front_ptr;
    *front_ptr = node;

    return true;

}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *node = create_node_list(elem);
    double_list_t list = *front_ptr;

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

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    doublelist_node_t *node = create_node_list(elem);
    double_list_t linked_list = *front_ptr;

    if (position == 0)
        return double_list_add_elem_at_front(front_ptr, elem);
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
