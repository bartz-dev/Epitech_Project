/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** isalpha.c
*/

#include "navy.h"

int char_isalpha(char c)
{
    if (c >= 'A' && c <= 'H')
        return 1;
    return 0;
}