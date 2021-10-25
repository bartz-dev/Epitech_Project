/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** stacking position
*/

#include "my.h"

#ifndef _PLAYER_POS_T_
#define _PLAYER_POS_T_

typedef struct player_pos_s
{
    int x;
    int y;
    int max;
    int p;
} player_pos_t;

void check_Ykey(char *path,player_pos_t *player, int key);
void start(player_pos_t *player, char *path);
void write_pos(player_pos_t *player, int key, char *path);
void check_case(player_pos_t *player, int key, char *path);
#endif