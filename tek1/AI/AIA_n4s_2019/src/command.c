/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** command.c
*/

#include "n4s.h"

int get_pos(char *str, int fd, nfs_t *nfs)
{

    my_putstr(str);
    str = get_next_line(fd);
    if (check_pos(str, nfs) == 1)
        return 1;
    return 0;
}

int check_pos(char *str, nfs_t *nfs)
{
    int i = my_strlen(str) - 1;
    int p = 0;
    char *new = malloc(sizeof(char *) * my_strlen(str));

    while (str[i] != ':' && str[i] != 0)
        i -= 1;
    i -= 1;
    while (str[i] != ':' && str[i] != 0)
        i -= 1;
    i += 1;
    while (str[i] != ':' && str[i] != 0)
        new[p++] = str[i++];
    new[p] = 0;
    if (my_strcmp("Track Cleared", new) == 0) {
        free(new);
        get_pos(nfs->stop, 0, nfs);
        return 1;
    }
    free(new);
    return 0;
}

char *check_str(char *str)
{
    int a = 0;
    int b = 0;
    char *tmp;

    if ((tmp = malloc(sizeof(char *) * 100)) == NULL)
        return (NULL);
    while (a != 3)
        if (str[b++] == ':')
            a++;
    a = 0;
    while (str[b] != 0) {
        if ((str[b] >= '0' && str[b] <= '9')
            || str[b] == '.' || str[b] == ':') {
            tmp[a] = str[b];
            a++;
        }
        b++;
    }
    tmp[a - 1] = '\0';
    return (tmp);
}