/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-clement.fleur
** File description:
** main.c
*/

#include "menger.h"

int main(int ac, char **av)
{
    if (ac == 3 && error_handling(ac, atoi(av[1]), av[2]) != -1) {
        menger_config_t config = { atoi(av[1]), atoi(av[2]) };
        vector_t coordinate = {0, 0};
        menger(coordinate, config, 0);
    } else {
        write(2, "Error\n", 6);
        exit(84);
    }

    return 0;
}

int error_handling(int ac, int ordinate, char *levels)
{
    if (ordinate % 3 != 0) {
        return -1;
    }

    for (int i = 0; levels[i]; i++) {
        if (levels[i] < '0' || levels[i] > '9') {
            return -1;
        }
    }

    if (ordinate < puissance(3, atoi(levels))) {
        return -1;
    }

    return 0;
}

int puissance(int base, int x)
{
    if (x == 0) {
        return 1;
    } else if (base == 0) {
        return 0;
    } else {
        return base * puissance(base, x - 1);
    }
}