/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"
#include <stdlib.h>

linked_list_t *ll_pop(linked_list_t *list)
{
    linked_list_t *i = list;

    if (!i || !i->next) return 0;
    while (((linked_list_t *)(i->next))->next) i = i->next;
    i->next = 0;
    return list;
}