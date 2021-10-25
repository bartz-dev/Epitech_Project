/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** exec.c
*/

#include "shell2.h"
#include "my.h"

int cd(char *cmd)
{
    char *arg;
    arg = my_argselect(cmd, 3);
    my_putstr(arg);
}

char *my_argselect(char *s,int first)
{
    int p = 0;
    int len = my_strlendeli(s, first);
    char *new_str = malloc(sizeof(char) * len + 2);

    for (int i = first; i < first + len + 1; i++, p++) {
        new_str[p] = s[i];
    }
    new_str[p] = '\0';
    return new_str;
}

int my_strlendeli(char *str, int start)
{
    int count = 0;

    while (str[start] != '\0') {
        count++;
        start++;
    }
    return count - 1;
}