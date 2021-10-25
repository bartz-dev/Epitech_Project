/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** 
*/

#include <stdlib.h>
#include "mylist.h"

linked_list_t *my_params_to_list(char *const *av, int ac)
{
    linked_list_t *element = 0;
    linked_list_t *tmp = 0;
    int count = 0;

    while (count < ac) {
        tmp = malloc(sizeof(linked_list_t));
        tmp->data = (av[count]);
        tmp->next = element;
        final = tmp;
        count++;
    }
    return final;
}
