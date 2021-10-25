/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-clement.fleur
** File description:
** func_ptr.c
*/

#include "func_ptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    char *new_str = malloc(sizeof(char) * strlen(str));

    for (int i = 0; str[i]; i++) {
        new_str[i] = str[i];
        if (str[i] <= 'z' && str[i] >= 'a')
            new_str[i] = str[i] - 32;
    }
    printf("%s\n", new_str);
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    action_exec_t list[] = {
    {PRINT_NORMAL, print_normal}, {PRINT_REVERSE, print_reverse},
    {PRINT_UPPER, print_upper}, {PRINT_42, print_42}
    };

    for (int i = 0; i < 4; i++) {
        if (list[i].flag == action)
            list[i].fct(str);
    }
}