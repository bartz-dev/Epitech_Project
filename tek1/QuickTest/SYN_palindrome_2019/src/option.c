/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** option.c
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    char *new_str = malloc(sizeof(char) * my_strlen(str));
    int p = my_strlen(str) - 1;

    for (int i = 0; str[i] != 0; i++, p--) {
        new_str[i] = str[p];
    }
    new_str[my_strlen(str)] = 0;
    return new_str;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}