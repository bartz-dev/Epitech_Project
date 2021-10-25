/*
** EPITECH PROJECT, 2019
** list
** File description:
** by clement fleur
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

linked_list_t *my_params_to_list(char *const *av);

#endif /*!LIST_H_ */
