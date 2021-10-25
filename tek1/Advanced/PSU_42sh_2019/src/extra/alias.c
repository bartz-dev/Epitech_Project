/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** history.c
*/

#include "shell.h"
#include <stdio.h>

int create_alias(int argc, char **argv, dictionary_t **env ,const char *text)
{
    FILE *f = fopen(my_strconcat(dict_get(*env, "HOME"), "/.42_alias"), "a");

    UNUSED(argc);
    UNUSED(argv);
    if (f == NULL) {
        perror("Create alias:");
        return 84;
    }
    fprintf(f, "%s\n", text);
    fclose(f);
    return 0;
}

int display_aliases(int argc, char **argv, dictionary_t **env)
{
    UNUSED(argc);
    UNUSED(argv);
    if (fopen(my_strconcat(dict_get(*env, "HOME"), "/.42_alias"), "r") == NULL){
        perror("Display alias");
        return 84;
    }
    my_printf(read_file(my_strconcat(dict_get(*env, "HOME"), "/.42_alias")));
    return 0;
}