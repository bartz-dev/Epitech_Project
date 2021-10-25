/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"
#include <stdlib.h>

linked_list_t *ll_prepend(linked_list_t *list, void *value)
{
    linked_list_t *new_list = malloc(sizeof(linked_list_t));

    new_list->data = value;
    new_list->next = list;
    return new_list;
}