/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d01_2019
** File description:
** show_string.c
*/

#include "phoenix.h"
#include <stdlib.h>
#include <unistd.h>

int my_putstr(char const *str)
{
    int len = 0;

    while (*str == '0')
        str++;
    if (str[len] == '\0')
        write(1, "0", 1);
    while (str[len] != '\0')
        len++;
    write(1, str, len);
}