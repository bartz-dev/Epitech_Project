/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** main.c
*/

#include <ncurses.h>
#include "my.h"
#include "tetris.h"

int main(int ac, char **argv)
{
    if (my_strcmp(argv[1], "-h") == 1 || my_strcmp(argv[1], "--help") == 1) {
        helping();
        return 0;
    }
    /*initscr();
    curs_set(0);
    refresh();
    endwin();*/

    return 0;
}