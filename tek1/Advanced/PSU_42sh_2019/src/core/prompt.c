/*
** EPITECH PROJECT, 2020
** prompt
** File description:
** prompt
*/

#include "shell.h"
#include <stdio.h>

char *get_command_line(void)
{
    char *command_line = NULL;
    size_t n = 0;

        if (getline(&command_line, &n, stdin) == -1)
            return 0;
        else
            return command_line;
}

char *get_current_dir(dictionary_t *env)
{
    char *current_dir = dict_get(env, "PWD");
    int incr = 0;
    int slash_count = 0;
    int count = 0;

    if (current_dir == 0) return 0;
    while (current_dir[incr] != 0) {
        if (current_dir[incr] == '/')
            slash_count++;
        incr++;
    }
    incr = 0;
    while (count < slash_count) {
        if (current_dir[incr] == '/')
            count++;
        incr++;
    }
    return current_dir = (char *) dict_get(env, "PWD") + incr;
}

int display_prompt(dictionary_t *env)
{
    char *user;
    char *host = read_file("/etc/hostname");
    char *current_dir;
    int length = my_strlen(host) - 1;

    if (host)
        host[length] = 0;
    user = dict_get(env, "USER");
    current_dir = get_current_dir(env);
    my_printf("[%s%s%s %s]%c ", user ? user : "",
        user && host ? "@" : "", host ? host : "",
        current_dir ? current_dir : "", get_uid(user) == 0 ? '#' : '$');
    return 0;
}