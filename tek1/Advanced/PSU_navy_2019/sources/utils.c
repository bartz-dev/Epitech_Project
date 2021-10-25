/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** destroy.c
*/

#include "navy.h"

char *get_info(void)
{
    char *buff = malloc(sizeof(char) * 3);
    int result = 0;

    result = read(0, buff, 4);
    if (result == -1 || result != 3) {
        free(buff);
        buff = NULL;
    }
    else
        buff[2] = '\0';
    return buff;
}

void my_kill(int sig, int pid)
{
    kill(pid, sig);
    usleep(100);
}