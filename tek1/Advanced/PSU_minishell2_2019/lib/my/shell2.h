/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** shell2.h
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>

#ifndef __SHELL__
#define __SHELL__
#define true (1)

typedef struct shell2_s
{
    /* data */
} shell2_t;

char *init_env(void);
char **findcmd(char *cmd, int len);

#endif // ! __SHELL__ ! \\