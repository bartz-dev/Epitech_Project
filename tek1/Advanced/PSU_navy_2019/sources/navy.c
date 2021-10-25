/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.c
*/

#include "navy.h"

int server_is_playing(char **map, char **enemy_map)
{
    int static ships = 14;
    char *attack = NULL;

    attack = get_info_attack(enemy_map);
    send_attack(attack, enemy_map);
    if (receive_ping_game_end(map, enemy_map) == 1)
        return 1;
    ships = receive_attack(map, ships);
    if (send_ping_game_end(ships, map, enemy_map) == 1)
        return 1;
    free(attack);
    return 0;
}

int client_is_playing(char **map, char **enemy_map)
{
    int static ships = 14;
    char *attack = NULL;

    ships = receive_attack(map, ships);
    if (send_ping_game_end(ships, map, enemy_map) == 1)
        return 1;
    attack = get_info_attack(enemy_map);
    send_attack(attack, enemy_map);
    if (receive_ping_game_end(map, enemy_map) == 1)
        return 1;
    free(attack);
    return 0;
}

int play_game(char **map, char **enemy_map, int user)
{
    int result = 0;

    if (user == 1)
        result = server_is_playing(map, enemy_map);
    if (result == 1)
        return 1;
    if (user == 2)
        result = client_is_playing(map, enemy_map);
    if (result == 1)
        return 1;
    return 0;
}

int run_navy(char **map, char **pos, int user)
{
    bool game = true;
    char **enemy_map = create_map(enemy_map);
    int i = 0;

    map = strategical_add(map, pos);
    while (game == true) {
        print_game(map, enemy_map);
        i = play_game(map, enemy_map, user);
        if (i != 0)
            game = false;
    }
    return i;
}