/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** parse_redirections
*/

#include "shell.h"

linked_list_t *create_redirection_list(char *str)
{
    char *beginning = str;
    int i;
    linked_list_t *list = 0;
    char *which;

    if (!str) return 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != '<' && str[i] != '>' &&
            !my_str_startswith(str + i, "<<") &&
            !my_str_startswith(str + i, ">>")) continue;
        which = my_str_startswith(str + i, "<<") ? "<<" :
            (my_str_startswith(str + i, ">>") ? ">>" : str[i]);
        str[i] = '\0';
        list = ll_append(list, my_strdup(beginning));
        list = ll_append(list, my_strdup(which));
        beginning = str + i + my_strlen(which);
        i += my_strlen(which) - 1;
    }
    if (beginning != str + i) list = ll_append(list, my_strdup(beginning));
    return list;
}

command_return_t parse_redirections(char *command)
{
    linked_list_t *parsed = create_redirection_list(command);

    for (linked_list_t *i = parsed; i; i = i->next) {

    }
}