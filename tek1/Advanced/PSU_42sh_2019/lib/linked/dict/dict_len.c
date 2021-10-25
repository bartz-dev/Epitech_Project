/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** dict_len
*/

#include "linked.h"

int dict_len(dictionary_t *dict)
{
    dictionary_t *iterator = dict;
    int i = 0;

    while (iterator) {
        i++;
        iterator = iterator->next;
    }
    return i;
}