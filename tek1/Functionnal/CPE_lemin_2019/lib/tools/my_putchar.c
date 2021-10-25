/*
** EPITECH PROJECT, 2019
** a
** File description:
** a
*/

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, 1);
}
