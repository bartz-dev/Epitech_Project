/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** game.c
*/

#include "navy.h"

int send_ping_game_end(int ships, char **map, char **enemy_map)
{
    if (ships == 0) {
        print_game(map, enemy_map);
        my_printf("\nEnemy won\n");
        my_kill(SIGUSR1, receive[0]);
        receive[3] = 1;
        return 1;
    } else
        my_kill(SIGUSR2, receive[0]);
    return 0;
}

int receive_ping_game_end(char **map, char **enemy_map)
{
    signal(SIGUSR1, end_handler);
    signal(SIGUSR2, end_handler);
    pause();
    if (receive[3] == 1) {
        print_game(map, enemy_map);
        my_printf("\nI won\n");
        receive[3] = 0;
        return 1;
    }
    return 0;
}

int check_if_already_attacked(char **enemy_map, char *buff)
{
    int j = buff[0] - 64;
    int i = buff[1] - 48;

    if (enemy_map[i - 1][j * 2] == 'x' || enemy_map[i - 1][j * 2] == 'o')
        return 1;
    return 0;
}

char *get_info_attack(char **enemy_map)
{
    char *buff = NULL;
    int i = 0;

    my_printf("\nattack: ");
    buff = get_info();
    while (buff == NULL || char_isalpha(buff[0]) == 0 || isnum(buff[1]) == 0
        || check_if_already_attacked(enemy_map, buff) == 1) {
        my_printf("wrong position");
        free(buff);
        my_printf("\nattack: ");
        buff = get_info();
    }
    return buff;
}
