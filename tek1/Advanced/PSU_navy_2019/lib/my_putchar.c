/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** lib - mehdi.zehri
*/

#include <unistd.h>
#include "navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
