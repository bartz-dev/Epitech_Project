/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2019
** File description:
** main.c
*/

#include "include/my.h"
#include "include/palindrome.h"
#include <stdio.h>

int check_multiplarg(int ac, char **av)
{
    int check = 0;

    for (int i = 0; i != ac; i++) {
        if (my_strcmp(av[i], "-p") == 1)
            check++;
        else if (my_strcmp(av[i], "-n") == 1)
            check++;
    }
    if (check != 1)
        return 84;
    return 0;
}

int error_handling(int ac, char **av)
{
    if (ac < 3)
        return 84;
    if (check_int(av, ac) == 84 || check_nbr(av, ac) == 84
        || check_base(av, ac) == 84) {
        my_putstr("invalid argument\n");
        return 84;
    }
    if (check_multiplarg(ac, av) == 84) {
        my_putstr("invalid argument\n");
        return 84;
    }
    return 0;
}

void check_option(palindrome *pal, char **av, int ac)
{
    int i = 3;
    char *tab[] = {"-imin", "-imax", "-b", 0};
    int nbr[] = {0, 100, 10};

    while (i < ac) {
        for (int p = 0; tab[p] != 0; p++) {
            if (my_strcmp(tab[p], av[i]) == 1)
                nbr[p] = my_getnbr(av[i + 1]);
        }
        i = i + 2;
    }
    pal->imin = nbr[0];
    pal->imax = nbr[1];
    pal->base = nbr[2];
}

void init_struct(palindrome *pal, char **av, int ac)
{
    if (my_strcmp(av[1], "-n") == 1) {
        pal->number = my_getnbr(av[2]);
        check_option(pal, av, ac);
    }
    else if (my_strcmp(av[1], "-p") == 1) {
        pal->number = my_getnbr(av[2]);
        check_option(pal, av, ac);
    }
}

int main(int ac, char **av)
{
    palindrome pal;
    int checker = 0;

    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    if (error_handling(ac, av) == 84)
        return 84;
    init_struct(&pal, av, ac);
    if (my_strcmp(av[1], "-p") == 1)
        checker = palind(&pal);
    else
        checker = palindromic(&pal);
    if (checker == 0)
        my_putstr("no solution\n");
    return 0;
}