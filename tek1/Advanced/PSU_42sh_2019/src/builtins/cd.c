/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** cd.c
*/

#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

char *cd_replace_home(dictionary_t *env_vars, char *dir)
{
    char *home;

    if (my_str_startswith(dir, "~")) {
        home = dict_get(env_vars, "HOME");
        if (home == UNDEFINED) return 0;
        dir = my_strconcat(home, dir + 1);
    }
    return dir;
}

int try_chdir(char *dir)
{
    if (chdir(dir)) {
        perror("cd");
        free(dir);
        return -1;
    }
    return 0;
}

int builtin_cd(int argc, char **argv, dictionary_t **env_vars)
{
    char *dir;
    char *temp;

    if (argc < 2) dir = "~";
    else if (!my_strcmp(argv[1], "-")) {
        temp = dict_get(*env_vars, "OLDPWD");
        if (!temp) return -1;
        dir = my_strdup(temp);
    } else dir = my_strdup(argv[1]);
    dir = cd_replace_home(*env_vars, dir);
    if (!dir) return -1;
    if (try_chdir(dir)) return -1;
    temp = dict_get(*env_vars, "PWD");
    if (temp) *env_vars = env_set(*env_vars, "OLDPWD", temp);
    temp = getcwd(NULL, 0);
    *env_vars = env_set(*env_vars, "PWD", temp);
    free(temp);
    free(dir);
    return 0;
}