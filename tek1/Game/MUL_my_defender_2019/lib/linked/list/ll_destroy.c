/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** linked_list
*/

#include "linked.h"
#include <stdlib.h>

void ll_destroy(linked_list_t *list)
{
    if (!list) return;
    if (list->next) ll_destroy(list->next);
    free(list);
}

void ll_v_destroy_c(void *list)
{
    ll_destroy_content((linked_list_t *) list);
    ll_destroy((linked_list_t *) list);
}

void ll_v_destroy(void *list)
{
    ll_destroy((linked_list_t *) list);
}

void ll_destroy_content(linked_list_t *list)
{
    linked_list_t *iterator = list;

    while (iterator) {
        free(iterator->data);
        iterator = iterator->next;
    }
}

void ll_free(linked_list_t *list, void (free_content)(void *))
{
    if (list) {
        if (list->next) ll_free(list->next, free_content);
        free_content(list->data);
        free(list);
    }
}