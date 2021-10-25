/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** environment
*/

#include <stdlib.h>
#include "shell.h"

dictionary_t *env_init(char **envp)
{
    char **this_var;
    dictionary_t *env_vars = 0;

    for (int i = 0; envp[i]; i++) {
        this_var = my_strsplit(envp[i], '=');
        env_vars = dict_add(env_vars, this_var[0],
            my_strjoin(this_var + 1, "="));
        free(this_var);
    }
    return env_vars;
}

dictionary_t *env_set(dictionary_t *env_vars, char *index, char *value)
{
    if (!dict_get(env_vars, index)) env_vars =
        dict_add(env_vars, my_strdup(index), my_strdup(value));
    else dict_set(env_vars, index, my_strdup(value));
    return env_vars;
}

char **env_to_array(dictionary_t *env_vars)
{
    int count = 1;
    char **env_arr;

    for (dictionary_t *i = env_vars; i; i = i->next) count++;
    env_arr = malloc(sizeof(char *) * count);
    count = 0;
    for (dictionary_t *i = env_vars; i; i = i->next) {
        env_arr[count] = my_strconcat(i->index, "=");
        env_arr[count] = my_free_assign(env_arr[count],
            my_strconcat(env_arr[count], i->data));
        count++;
    }
    env_arr[count] = 0;
    return env_arr;
}