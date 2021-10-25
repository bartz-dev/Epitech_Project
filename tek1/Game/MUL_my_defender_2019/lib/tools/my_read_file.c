/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** my_f_get_content
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *read_file(char *filepath)
{
    char *buff;
    int offset = 0;
    int len;
    int file;
    struct stat stats;

    file = open(filepath, O_RDONLY);
    if (file == -1)
        return 0;
    stat(filepath, &stats);
    buff = malloc(sizeof(char) * (stats.st_size + 1));
    while ((len = read(file, buff + offset, stats.st_size - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    close(file);
    return buff;
}