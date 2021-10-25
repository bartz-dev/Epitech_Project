/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d03_2019
** File description:
** my_putchar.c
*/
#include <unistd.h>
#include "phoenix.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}