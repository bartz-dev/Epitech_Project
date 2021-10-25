/*
** EPITECH PROJECT, 2020
** command_check
** File description:
** command_check
*/

#include "shell.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int check_folder(char *folder_path, char *binary)
{
    DIR *dir_stream = opendir(folder_path);
    struct dirent *file_infos = readdir(dir_stream);

    while (file_infos != 0) {
        if (my_strcmp(file_infos->d_name, binary) == 0) {
            closedir(dir_stream);
            return 0;
        }
        file_infos = readdir(dir_stream);
    }
    return 1;
}

char *check_existence(dictionary_t *env, char *binary_name)
{
    char *path = dict_get(env, "PATH");
    char **parsed_path = parse_path(path);
    int binary_exist = 1;
    int line = 0;

    while (parsed_path[line] != 0) {
        binary_exist = check_folder(parsed_path[line], binary_name);
        if (binary_exist == 0) return parsed_path[line];
        line++;
    }
    binary_exist = check_folder(dict_get(env, "PWD"), binary_name);
    if (binary_exist == 0) return dict_get(env, "PWD");
    return 0;
}

int check_right(char *binary_path, char *binary_name)
{
    int right;

    binary_path = my_strconcat(binary_path, my_strconcat("/", binary_name));
    right = access(binary_path, X_OK);
    return right;
}

int check_command(int argc, char **argv, dictionary_t *env)
{
    char *binary_name = /*Entrer le nom du binaire à rechercher ici*/;
    char *bin_folder = check_existence(env, binary_name);
    int right;

    if (bin_folder != 0) right = check_right(bin_folder, binary_name);
    else return 1;
    if (right == 0) {
        /*Continuer le code ici*/
    } else return 2;
    return 0;
}