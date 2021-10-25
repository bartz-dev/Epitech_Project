/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** main.c
*/

#include "my.h"
#include "shell2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char** envp)
{
    int checker = 0;
    char *path = "< ";
    char *pwd;
    char *str;
    char **tab; // = init_function();
    char **order;
    size_t buff_size = 5;

    if (my_strcmp(pwd = init_env(envp), "ERROR84") == 1) {
        my_putstr("Error can't read you're PWD in env var");
        return 84;
    }
    while (true) {
        my_putstr(pwd);
        my_putstr(": ");
        if (checker = getline(&str, &buff_size, stdin) < 0)
            return 84;
        order = findcmd(str, my_strlen(str) - 1);
    }
    return 0;
}