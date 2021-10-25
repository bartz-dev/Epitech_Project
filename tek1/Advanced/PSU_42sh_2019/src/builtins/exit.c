/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** exit.c
*/

#include "shell.h"
#include <stdlib.h>

int builtin_exit(int argc, char **argv, dictionary_t **env)
{
    int exit_status = 0;

    UNUSED(env);
    if (argc >= 2)
        exit_status = my_getnbr(argv[1]);
    exit(exit_status);
}