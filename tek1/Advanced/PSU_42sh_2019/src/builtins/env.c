/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** env.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"

int builtin_env(int argc, char **argv, dictionary_t **env)
{
    UNUSED(argv);
    UNUSED(argc);
    for (dictionary_t *i = *env; i; i = i->next)
        my_printf("%s=%s\n", i->index, i->data);
    return 0;
}

int builtin_setenv(int argc, char **argv, dictionary_t **env)
{
    char *value = "";

    if (argc == 1)
        return builtin_env(0, 0, env);
    else if (argc >= 3)
        value = argv[2];
    *env = env_set(*env, argv[1], value);
    return 0;
}

int builtin_unsetenv(int argc, char **argv, dictionary_t **env)
{
    if (argc < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return 1;
    }
    *env = dict_remove(*env, argv[1]);
    return 0;
}