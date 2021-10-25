/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** ll_remove
*/

#include "linked.h"

linked_list_t *ll_remove_middle(linked_list_t *list, int index)
{
    linked_list_t *iterator = list;
    linked_list_t *temp;
    int i = 0;

    while (iterator) {
        if (i == index - 1) {
            temp = iterator->next;
            iterator->next = ((linked_list_t *)(iterator->next))->next;
            temp->next = 0;
            ll_destroy(temp);
        }
        i++;
        iterator = iterator->next;
    }
    return list;
}

linked_list_t *ll_remove(linked_list_t *list, int index)
{
    if (index == 0) return ll_shift(list);
    else if (index >= ll_len(list)) return ll_pop(list);
    else return ll_remove_middle(list, index);
}