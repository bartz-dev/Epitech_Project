/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** help.c
*/

#include "../include/my.h"

void help(void)
{
    my_putstr("USAGE\n      ./palindrome -n number -p palindrome [-b base] [");
    my_putstr("-imin i] [-imax i]\n\nDESCRIPTION\n      -n n      integer to");
    my_putstr(" be transformed (>=0)\n      -p pal    palindromic number to ");
    my_putstr("be obtained (incompatible with the -n\n                ");
    my_putstr("option) (>=0)\n                if defined, all fitting values");
    my_putstr(" of n will be output\n      -b base   base in which the proc");
    my_putstr("edure will be executed (1<b<=10) [def: 10]\n      -imin i   ");
    my_putstr("minimum number of iterations, included (>=0) [def: 0]\n      ");
    my_putstr("-imax i   maximum number of iterations, included (>=0) [def: ");
    my_putstr("100]\n");
}