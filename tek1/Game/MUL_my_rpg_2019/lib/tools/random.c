/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** random
*/

#include <stdlib.h>

int irand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}