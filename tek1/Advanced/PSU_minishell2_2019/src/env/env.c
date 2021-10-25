/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** env.c
*/

#include "shell2.h"

char *init_env(char **env2)
{
    char **env;
    char *pwd;

    for(env=env2;*env!=0;env++) {
        pwd = *env;
        if (pwd[0] == 'P' && pwd[1] == 'W' && pwd[2] == 'D')
            return my_argselect(pwd, 4);
    }
    return "ERROR84";
}