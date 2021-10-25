/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays the given string
*/

#include "tools.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    return write(1, str, my_strlen(str));
}