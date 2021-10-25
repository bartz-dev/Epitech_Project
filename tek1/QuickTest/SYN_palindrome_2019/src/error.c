/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** error.c
*/

#include "../include/my.h"

int check_base(char **av, int ac)
{
    for (int i = 1; i != ac; i++) {
        if (my_strcmp(av[i], "-b") == 1 && (my_getnbr(av[i + 1]) < 2
            || my_getnbr(av[i + 1]) > 10))
                return 84;
    }
    return 0;
}

int check_nbr(char **av, int ac)
{
    for (int i = 1; i != ac; i++) {
        if (my_strcmp(av[i], "-p") == 1 || my_strcmp(av[i], "-n") == 1)
            if (my_getnbr(av[i + 1]) <= 0)
                return 84;
    }
    return 0;
}

int check_flagnb(char *flag)
{
    if (my_strcmp(flag, "-p") == 1 || my_strcmp(flag, "-n") == 1 ||
        my_strcmp(flag, "-imin") == 1 || my_strcmp(flag, "-imax") == 1
        || my_strcmp(flag, "-b") == 1)
        return 0;
    else if (flag >= 58 || flag <= 47)
        return 1;
    else
        return 84;

}

int check_flag(char **av, int ac)
{
    int i = 0;

    for (int p = 1; p != ac; p++) {
        while (av[p][i] != 0) {
            if ((av[p][i] > '9' || av[p][i] < '0') && check_flagnb(av[p]) == 84)
                return 84;
            i++;
        }
    }
    return 0;
}

int check_int(char **av, int ac)
{
    int p = 0;

    for (int i = 1; i != ac; i++) {
        while (av[i][p] != 0) {
            if (check_flagnb(av[i]) == 0)
                i = i + 1;
            if (av[i][p] >= 48 && av[i][p] <= 57)
                p++;
            else
                return 84;
        }
        p = 0;
    }
    if (check_flag(av, ac) == 84)
        return 84;
    return 0;
}