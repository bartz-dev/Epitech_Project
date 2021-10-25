/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban essential function to move
*/

#include <ncurses.h>
#include "pos.h"


void check_case(player_pos_t *play, int key, char *path)
{
    switch (key) {
        case KEY_LEFT: if (path[play->y * play->max + play->x - 1] != '#') {
            path[play->y * play->max + play->x - 1] = 'X';
            path[play->y * play->max + play->x] = ' ';
            write_pos(play, key, path);
        } break;
        case KEY_RIGHT: if (path[play->y * play->max + play->x + 1] != '#') {
            path[play->y * play->max + play->x + 1] = 'X';
            path[play->y * play->max + play->x] = ' ';
            write_pos(play, key, path);
        } break;
        case KEY_DOWN: if (path[(play->y + 1) * play->max + play->x] != '#') {
            path[(play->y + 1) * play->max + play->x] = 'X';
            path[play->y * play->max + play->x] = ' ';
            write_pos(play, key, path);
        } break;
        case KEY_UP: if (path[(play->y - 1) * play->max + play->x] != '#') {
            path[(play->y - 1) * play->max + play->x] = 'X';
            path[play->y * play->max + play->x] = ' ';
            write_pos(play, key, path);
        } break;
    }
}

void write_pos(player_pos_t *player, int key, char *path)
{
    player->p = player->y * player->max + player->x;
    if (path[player->y * player->max + player->x] != 'X') {
        switch (key) {
        case KEY_LEFT: path[player->y * player->max + player->x + 1] = ' ';
            path[player->y*player->max+player->x] = 'P';
            break;
        case KEY_RIGHT: path[player->y * player->max + player->x - 1] = ' ';
            path[player->y*player->max+player->x] = 'P';
            break;
        case KEY_DOWN: path[(player->y - 1) * player->max + player->x] = ' ';
            path[player->y*player->max+player->x] = 'P';
            break;
        case KEY_UP: path[(player->y + 1) * player->max + player->x] = ' ';
            path[player->y*player->max+player->x] = 'P';
            break;
        default:
            break;
        }
    }
    else if (path[player->p] == 'X')
        check_case(player, key, path);
}

void check_Ykey(char *path,player_pos_t *play, int key)
{
    switch (key) {
        case KEY_LEFT: if (path[play->y * play->max + play->x - 1] != '#') {
            play->x = play->x - 1;
            write_pos(play, key, path);
        } break;
        case KEY_RIGHT: if (path[play->y * play->max+play->x + 1] != '#') {
            play->x = play->x + 1;
            write_pos(play, key, path);
        } break;
        case KEY_DOWN: if (path[(play->y + 1) * play->max+ play->x] != '#') {
            play->y = play->y + 1;
            write_pos(play, key, path);
        } break;
        case KEY_UP: if (path[(play->y - 1) * play->max + play->x] != '#') {
            play->y = play->y - 1;
            write_pos(play, key, path);
        } break;
        default:
            break;
    }
}

void start(player_pos_t *player, char *path)
{
    int key;

    keypad(stdscr, TRUE);
    noecho();
    while (1) {
        mvprintw(0,0, path);
        key = getch();
        if (key == 27) {
            break;
            refresh();
        }
        if (key == 32) {
            move(0,0);
            pos_player(path);
        }
        move(player->y, player->x);
        check_Ykey(path, player, key);
        refresh();
    }
}