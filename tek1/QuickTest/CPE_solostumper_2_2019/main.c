/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** by clement fleur
*/

#include <unistd.h>

void my_putstr(char *string)
{
    int i = 0;

    while (string[i] != 0) {
        write(1, &string[i], 1);
        i++;
    }
}

int my_strlen(char *path)
{
    int i = 0;

    while (path[i] != 0)
        i++;
    return i;
}

char *checkmaj(char *path)
{
    int i = 0;

    while (path[i] != 0) {
        if (path[i] >= 65 && path[i] <= 90)
            path[i] = path[i] + 32;
        i++;
    }
    return path;
}

int palindrome(char *path)
{
    int i = 0;
    int p = 0;
    int m = my_strlen(path) - 1;
    char *not = "not a palindrome.\n";

    path = checkmaj(path);
    if ((m + 1) % 2 != 0) {
        my_putstr(not);
        return 84;
    }
    i = (m + 1) / 2;
    while (p != i) {
        if (path[p] != path[m]) {
          my_putstr(not);
          return 84;
        }
        p++;
        m--;
    }
    my_putstr("palindrome!\n");
    return 0;
}

int main(int ac, char **argv)
{
    int nb;

    if (ac == 2)
        nb = palindrome(argv[1]);
    else {
        my_putstr("Error: missing arguments.");
        return 84;
    }
    if (nb == 84)
        return 84;
    return 0;
}
