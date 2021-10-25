/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-clement.fleur
** File description:
** get_linked_list.c
*/

#include "double_list.h"
#include "stddef.h"
#include <stdio.h>

unsigned int double_list_get_size(double_list_t list)
{
    int size = 0;

    while (list) {
        size++;
        list = list->next;
    }
    return size;
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    while (list) {
        if (list->value == value)
            return list;
        list = list->next;
    }
    return NULL;
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    if (position == 0)
        return double_list_get_elem_at_front(list);
    if (!list)
        return (0);
    for (unsigned int i = 0; i < position; i++) {
        list = list->next;
        if (!list)
            return 0;
    }
    return (list->value);
}

double double_list_get_elem_at_front(double_list_t list)
{
    if (!list) {
        return 0;
    }
    return list->value;
}

double double_list_get_elem_at_back(double_list_t list)
{
    if (!list)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}
