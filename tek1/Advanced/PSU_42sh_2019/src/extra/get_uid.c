/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_uid
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

int check_match(char *username, char **user_props, char **users)
{
    int uid;

    if (!my_strcmp(user_props[0], username)) {
        uid = my_getnbr(user_props[2]);
        free_split(user_props);
        free_split(users);
        return uid;
    }
    else return -1;
}

int get_uid(char *username)
{
    char **users;
    char **user_props;
    char *passwd = read_file("/etc/passwd");
    int return_value;

    if (!username || !passwd) return -1;
    users = my_strsplit(passwd, '\n');
    free(passwd);
    users[my_arrlen(users) - 1] = 0;
    for (int i = 0; users[i]; i++) {
        user_props = my_strsplit(users[i], ':');
        if ((return_value = check_match(username, user_props, users)) != -1)
            return return_value;
        free_split(user_props);
    }
    free_split(users);
    return -1;
}