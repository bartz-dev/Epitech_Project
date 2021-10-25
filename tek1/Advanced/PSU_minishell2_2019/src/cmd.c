/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** cmd.c
*/

#include "shell2.h"
#include "my.h"

void preparecmd(char *cmd)
{
    switch (cmd[0])
    {
    case ('c'): if (cmd[1] == 'd' && cmd [2] == ' ')
                    cd(cmd);
        break;

    default:
        break;
    }
}

char **addingtab(char **cmd, char *cmdline, int line)
{
    if (cmd == NULL)
        my_putstr("error");
    cmd[line] = malloc(sizeof(char) * (my_strlen(cmdline)));
    cmd[line] = cmdline;
    preparecmd(cmdline);
    return cmd;
}

char **redirect(int start, int end, char *cmd, char **command, int line)
{
    char *cmdline = malloc(sizeof(char) * (end - start));
    int p = 0;

    for (int i = start; i < end; i++, p++)
        cmdline[p] = cmd[i];
    cmdline[p+1] = 0;
    command = addingtab(command, cmdline, line);
    return command;
}

int findarg(char *cmd, int x, int start)
{
    while (cmd[x] != ';') {
        if (cmd[x] == '\0')
            return x;
        x = x + 1;
    }
    return x;
}

char **findcmd(char *cmd, int len)
{
    char **command = malloc(sizeof(*cmd) * my_strlen(cmd));
    int i = 0;
    int p =0;
    int line = 0;
    int start = 0;

    for (i = 0; i < len; i++, line++) {
        start = i;
        i = findarg(cmd, i, start);
        command = redirect(start, i, cmd, command, line);
    }
    /*while (command[p] != NULL) { print command
        printf(command[p]);
        p++;
    }*/
}