/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** exec.c
*/

#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

volatile __sig_atomic_t interrupt = 0;

void signal_handler(int sig)
{
    interrupt = 1;
}

void check_signal(int child)
{
    if (interrupt) {
        kill(child, SIGINT);
        interrupt = 0;
    }
}

int wait_loop(int child)
{
    int exit_status;
    int is_alive;

    while (1) {
        is_alive = waitpid(child, &exit_status, WNOHANG);
        if (is_alive == 0) {
            check_signal(child);
        } else
            return WEXITSTATUS(exit_status);
    }
}

command_return_t exec(command_t command)
{
    int child;
    int return_value;
    pipes_t pipes;
    command_return_t ret;

    pipe(pipes.stdin);
    pipe(pipes.stdout);
    if ((child = fork())) {
        return parent_exec(command, pipes, child);
    } else {
        child_exec(command, pipes);
        exit(0);
    }
}