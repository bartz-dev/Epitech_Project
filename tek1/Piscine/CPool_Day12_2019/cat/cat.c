/*
** EPITECH PROJECT, 2019
** cat
** File description:
** cat by clement fleur
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void check_letter(void)
{
    char buffer[32768];
    int size = 1;

    while (size != 0) {
        size = read(0, buffer, 32); 
        write(1, &buffer, size);
    }
}

int cat(int ac, char *av[])
{
    int i = 1;
    int size;
    char buffer[32768];
    int fd;

    if (ac == 1)
        check_letter();
    while (av[i] != av[ac]) {
        fd = open(av[i], O_RDONLY|O_CREAT, S_IRWXU);
        if (fd == -1)
            return 1;
        size = 1;
        while (size != 0) {
            size = read(fd, buffer, 19);
            write(1, buffer, size);
        }
        i++;
        close(fd);
    }
    return 0;
}

int main(int ac, char *av[])
{
    int i = 0;

    if (ac == 1)
        check_letter();
    else
        cat(ac, av);
    return 0;
}
