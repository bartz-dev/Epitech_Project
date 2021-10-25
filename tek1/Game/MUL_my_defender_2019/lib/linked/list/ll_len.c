/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"

int ll_len(linked_list_t *list)
{
    linked_list_t *iterator = list;
    int i = 0;

    while (iterator) {
        i++;
        iterator = iterator->next;
    }
    return i;
}