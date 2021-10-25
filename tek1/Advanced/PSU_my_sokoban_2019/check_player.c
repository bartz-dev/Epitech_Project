/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** fin position of the player
*/

#include <sys/stat.h>
#include "pos.h"
#include "ncurses.h"
#include "my.h"

void pos_player(char *path)
{
    int i = 0;
    int x = 0;
    player_pos_t player = {0};

    mvprintw(0, 0, path);
    while (path[i] != 'P') {
        if (path[i] == '\n') {
            player.max = x;
            x = 0;
            player.y = player.y + 1;
        }
        i++;
        x++;
    }
    player.x = x - 1;
    start(&player, path);
}