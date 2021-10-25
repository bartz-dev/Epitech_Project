/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** server.c
*/

#include "navy.h"

void client_is_connected(int sig, siginfo_t *info, void *context)
{
    receive[0] = info->si_pid;

    my_printf("\nenemy connected\n\n");
}

int init_server(char **map, char **pos)
{
    struct sigaction sa;

    my_printf("my_pid:\t%d\n", getpid());
    my_printf("waiting for enemy connection...\n");
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = client_is_connected;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
    if (kill(receive[0], SIGUSR2) == -1 || run_navy(map, pos, 1) == -1)
        return -1;
    return 0;
}
