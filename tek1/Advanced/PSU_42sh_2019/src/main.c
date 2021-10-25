/*
** EPITECH PROJECT, 2019
** PSU_42sh_2019
** File description:
** main.c
*/

#include "shell.h"
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
    dictionary_t *env = env_init(envp);
    dictionary_t *builtins = builtin_init();
    char *command_line;
    char buff[65536];
    int var = 1;

    UNUSED(argc);
    UNUSED(argv);
    if (isatty(0)) {
        while (var == 1) {
            display_prompt(env);
            command_line = get_command_line();
            if (!command_line)
                break;
            write_to_his(argc, argv, &env, command_line);
            parse_input(command_line, &env, builtins);
        }
    } else {
        read(0, &buff, 65536);
        parse_input(buff, &env, builtins);
    }
    return 0;
}