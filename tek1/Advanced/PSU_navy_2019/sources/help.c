/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** help.c
*/

#include "navy.h"

void help(void)
{
    my_printf("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n     first_player_pid: only for the 2nd player. ");
    my_printf("pid of the first player.\n");
    my_printf("     navy_positions: file representing the positions of the");
    my_printf(" ships.");
}