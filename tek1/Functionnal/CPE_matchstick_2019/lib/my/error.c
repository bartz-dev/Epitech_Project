/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** error.c
*/

#include "my.h"
#include <unistd.h>

int my_puterror(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}