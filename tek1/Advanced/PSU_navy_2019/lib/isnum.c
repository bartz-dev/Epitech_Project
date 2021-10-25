/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** isnum.c
*/

#include "navy.h"

int isnum(char c)
{
    if (c >= '1' && c <= '8')
        return 1;
    return 0;
}