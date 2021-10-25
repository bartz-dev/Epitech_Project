/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** ll_concat
*/

#include "linked.h"

linked_list_t *ll_concat(linked_list_t *a, linked_list_t *b)
{
    linked_list_t *i = a;

    if (!a) return b;
    if (!b) return a;
    while (i->next) i = i->next;
    i->next = b;
    return a;
}