/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** my_putchar by clement fleur
*/

#include <unistd.h>


void my_put_char(char c)
{
    write(1, &c, 1);
}
