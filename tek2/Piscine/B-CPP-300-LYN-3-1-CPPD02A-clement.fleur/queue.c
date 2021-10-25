/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-clement.fleur
** File description:
** queue.c
*/

#include "generic_list.h"
#include "queue.h"
#include <stddef.h>

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return list_add_elem_at_front(queue_ptr, elem);
}

bool queue_pop(queue_t *queue_ptr)
{
    list_get_elem_at_back(*queue_ptr);
    return list_del_elem_at_back(queue_ptr);
}

void *queue_front(queue_t queue)
{
    list_get_elem_at_back(queue);
}