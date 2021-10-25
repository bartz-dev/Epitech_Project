/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** attack.c
*/

#include "navy.h"

void send_attack(char *attack, char **enemy_map)
{
    int letter = attack[0] - 64;
    int number = attack[1] - 48;

    for (int i = letter; i != 0; i--)
        my_kill(SIGUSR1, receive[0]);
    for (int j = number; j != 0; j--)
        my_kill(SIGUSR2, receive[0]);
    my_kill(SIGUSR1, receive[0]);
    my_printf("%s: ", attack);
    if (result_attack() == 1)
        enemy_map[number - 1][letter * 2] = 'x';
    else
        enemy_map[number - 1][letter * 2] = 'o';
    receive[3] = 0;
}

int check_ennemy_attack(char **map)
{
    int i = receive[2] - 1;
    int j = receive[1] * 2;

    if (map[i][j] == '2' || map[i][j] == '3'
        || map[i][j] == '4' || map[i][j] == '5') {
        map[i][j] = 'x';
        my_printf("%c%d: hit\n", receive[1] + 64, receive[2]);
        usleep(1600);
        my_kill(SIGUSR1, receive[0]);
        return 1;
    } else {
        map[i][j] = 'o';
        usleep(1600);
        my_printf("%c%d: missed\n", receive[1] + 64, receive[2]);
        my_kill(SIGUSR2, receive[0]);
        return 0;
    }
}

int receive_attack(char **map, int ships)
{
    receive[1] = 0;
    receive[2] = 0;
    receive[3] = 0;
    my_printf("\nwaiting for enemy’s attack...\n");
    get_coord();
    if (check_ennemy_attack(map) == 1)
        ships--;
    return ships;
}