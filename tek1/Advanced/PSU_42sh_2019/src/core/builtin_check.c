/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** builtin_check
*/

#include "shell.h"

int builtin_check(int argc, char **argv, dictionary_t **env,
    dictionary_t *builtins)
{
    int (*builtin)(int, char **, dictionary_t **) = dict_get(builtins, argv[0]);

    if (builtin)
        return builtin(argc, argv, env);
    else {
        // TODO: exec program
    }
    return 0;
}