/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** client.c
*/

#include "navy.h"

void connected_to_server(int sig)
{
    my_printf("successfully connected\n\n");
    (void)sig;
}

int init_client(char **map, char **pos, int pid_server)
{
    struct sigaction sa;

    if (kill(pid_server, SIGUSR1) == -1)
        return -1;
    my_printf("my_pid:\t%d\n", getpid());
    signal(SIGUSR2, connected_to_server);
    pause();
    receive[0] = pid_server;
    if (run_navy(map, pos, 2) == -1)
        return -1;
    return 0;
}