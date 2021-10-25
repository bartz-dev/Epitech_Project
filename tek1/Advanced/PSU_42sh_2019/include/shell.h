/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_
#include "linked.h"
#include "tools.h"

#define _XOPEN_SOURCE 700

#define OPERATOR_NONE 0
#define OPERATOR_OR 1
#define OPERATOR_AND 2
#define OPERATOR_NEWLINE 3

typedef struct pipe_param {
    int pipe_stdout;
    char *stdin;
} pipe_param_t;

typedef struct pipes {
    int stdin[2];
    int stdout[2];
} pipes_t;

typedef struct command {
    char *command;
    int argc;
    char **argv;
    dictionary_t **env;
    int pipe_stdout;
    char *stdin;
} command_t;

typedef struct command_return {
    char *stdout;
    int return_value;
} command_return_t;

char *get_command_line(void);
int display_prompt(dictionary_t *env);
command_return_t parse_input(char *command, dictionary_t **env_vars,
    dictionary_t *builtins);
dictionary_t *env_init(char **envp);
dictionary_t *env_set(dictionary_t *env_vars, char *index, char *value);
char **env_to_array(dictionary_t *env_vars);
command_return_t builtin_cd(int argc, char **argv, dictionary_t **env_vars);
command_return_t builtin_exit(int argc, char **argv, dictionary_t **env_vars);
command_return_t builtin_echo(int argc, char **argv, dictionary_t **env);
command_return_t builtin_env(int argc, char **argv, dictionary_t **env_vars);
command_return_t builtin_setenv(int argc, char **argv, dictionary_t **env_vars);
command_return_t builtin_unsetenv(int argc, char **argv, dictionary_t **env_vars);
dictionary_t *builtin_init(void);
int get_uid(char *username);
command_return_t builtin_check(command_t command, dictionary_t *builtins);
int get_path_line(char *path);
char **malloc_parsed_path(char **parsed_path, char *path);
char **parse_path(char *path);
int check_folder(char *folder_path, char *binary);
char *check_existence(dictionary_t *env, char *binary_name);
command_return_t check_command(command_t command);
command_return_t exec(command_t command);
void signal_handler(int sig);
command_return_t parent_exec(command_t command, pipes_t pipes,
    int child_pid);
void child_exec(command_t command, pipes_t pipes);
command_return_t parse_pipes(char *command, dictionary_t **env_vars,
    dictionary_t *builtin);
command_return_t parse_command(char *command, dictionary_t **env_vars,
    dictionary_t *builtins, pipe_param_t params);
int display_history(int argc, char **argv, dictionary_t **env);
int write_to_his(int argc, char **argv, dictionary_t **env ,const char *text);
int create_alias(int argc, char **argv, dictionary_t **env ,const char *text);
int display_aliases(int argc, char **argv, dictionary_t **env);
int parcour_str(char *str);

#endif /* !SHELL_H_ */