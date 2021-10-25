/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** dict
*/

#include "shell.h"

dictionary_t *builtin_init(void)
{
    dictionary_t *builtins = dict_add(0, "cd", builtin_cd);

    builtins = dict_add(builtins, "echo", builtin_echo);
    builtins = dict_add(builtins, "exit", builtin_exit);
    builtins = dict_add(builtins, "env", builtin_env);
    builtins = dict_add(builtins, "setenv", builtin_setenv);
    builtins = dict_add(builtins, "unsetenv", builtin_unsetenv);
    return builtins;
}