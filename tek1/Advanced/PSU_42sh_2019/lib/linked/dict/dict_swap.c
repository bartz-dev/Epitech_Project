/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** dict_swap
*/

#include "tools.h"
#include "linked.h"

dictionary_t *d_swap(dictionary_t *list, dictionary_t *prev1,
    dictionary_t *prev2)
{
    dictionary_t *temp;
    dictionary_t *temp2;

    if (prev1) {
        temp = prev2->next;
        prev2->next = prev1->next;
        temp2 = ((dictionary_t *)(prev1->next))->next;
        ((dictionary_t *)(prev1->next))->next = temp->next;
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

dictionary_t *dict_swap(dictionary_t *list, int i1, int i2)
{
    dictionary_t *prev = 0;
    int i = 0;

    if (!list || !list->next || i1 < 0 || i2 < 0 || i1 == i2 ||
        i1 >= dict_len(list) || i2 >= dict_len(list)) return list;
    if (i1 > i2) my_swap(&i1, &i2);
    for (dictionary_t *it = list; it; it = it->next) {
        if (i == i1 - 1) prev = it;
        if (i == i2 - 1)
            return d_swap(list, prev, it);
        i++;
    }
    return list;
}