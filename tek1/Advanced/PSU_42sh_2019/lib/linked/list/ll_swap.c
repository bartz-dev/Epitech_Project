/*
** EPITECH PROJECT, 2020
** ll_swap
** File description:
** ll_swap
*/

#include "tools.h"
#include "linked.h"

linked_list_t *lswap(linked_list_t *list, linked_list_t *prev1,
    linked_list_t *prev2)
{
    linked_list_t *temp;
    linked_list_t *temp2;

    if (prev1) {
        temp = prev2->next;
        prev2->next = prev1->next;
        temp2 = ((linked_list_t *)(prev1->next))->next;
        ((linked_list_t *)(prev1->next))->next = temp->next;
        prev1->next = temp;
        temp->next = temp2;
    } else {
        temp = prev2->next;
        prev2->next = list;
        temp2 = list->next;
        list->next = temp->next;
        temp->next = temp2;
        return temp;
    }
    return list;
}

linked_list_t *ll_swap(linked_list_t *list, int i1, int i2)
{
    linked_list_t *prev = 0;
    int i = 0;

    if (!list || !list->next || i1 < 0 || i2 < 0 || i1 == i2 ||
        i1 >= ll_len(list) || i2 >= ll_len(list)) return list;
    if (i1 > i2) my_swap(&i1, &i2);
    for (linked_list_t *it = list; it; it = it->next) {
        if (i == i1 - 1) prev = it;
        if (i == i2 - 1)
            return lswap(list, prev, it);
        i++;
    }
    return list;
}