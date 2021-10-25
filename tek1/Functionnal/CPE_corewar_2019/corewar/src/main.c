/*
** EPITECH PROJECT, 2019
** folder
** File description:
** main.c
*/

#include "my.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./asm file_name[.s]\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr("file_name file in assembly language to be converted into ");
    my_putstr("file_name.cor, an\nexecutable in the Virtual Machine");
    return 84;
}

int main(int ac, char **av, char **envp)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        help();
    return 0;
}
