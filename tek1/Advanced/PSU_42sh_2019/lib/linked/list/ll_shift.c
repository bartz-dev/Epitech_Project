/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"
#include <stdlib.h>

linked_list_t *ll_shift(linked_list_t *list)
{
    linked_list_t *new_list = list->next;

    free(list);
    return new_list;
}