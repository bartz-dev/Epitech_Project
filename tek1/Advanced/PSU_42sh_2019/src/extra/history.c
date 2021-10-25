/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** history.c
*/

#include "shell.h"
#include <stdio.h>

int write_to_his(int argc, char **argv, dictionary_t **env ,const char *text)
{
    FILE *f = fopen(my_strconcat(dict_get(*env, "HOME"), "/.42sh_his"), "a");

    UNUSED(argc);
    UNUSED(argv);
    if (f == NULL) {
        perror("write to history");
        return 84;
    }
    fprintf(f, "%s", text);
    fclose(f);
    return 0;
}

int display_history(int argc, char **argv, dictionary_t **env)
{
    UNUSED(argc);
    UNUSED(argv);
    if (fopen(my_strconcat(dict_get(*env, "HOME"), "/.42sh_his"), "r") == NULL){
        perror("Display history");
        return 84;
    }
    my_printf(read_file(my_strconcat(dict_get(*env, "HOME"), "/.42sh_his")));
    return 0;
}