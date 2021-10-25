/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** get_sig.c
*/

#include "navy.h"

void attack_handling(int sig)
{
    if (sig == SIGUSR1 && receive[2] == 0)
        receive[1]++;
    else if (sig == SIGUSR2)
        receive[2]++;
    if (sig == SIGUSR1 && receive[2] > 0)
        receive[3] = 1;
}

void result_handling(int sig)
{
    if (sig == SIGUSR1) {
        my_printf("hit\n");
        receive[3] = 1;
    }
    if (sig == SIGUSR2) {
        my_printf("missed\n");
        receive[3] = 2;
    }
}

int result_attack(void)
{
    int result = 0;

    receive[3] = 0;
    signal(SIGUSR1, result_handling);
    signal(SIGUSR2, result_handling);
    pause();
    result = receive[3];
    receive[3] = 0;
    return result;
}

void get_coord(void)
{
    int letter = 0;
    int check = 0;

    while (receive[3] != 1) {
        signal(SIGUSR1, attack_handling);
        signal(SIGUSR2, attack_handling);
        signal(SIGUSR1, attack_handling);
    }
}

void end_handler(int sig)
{
    if (sig == SIGUSR2)
        return;
    if (sig == SIGUSR1) {
        receive[3] = 1;
    }
}