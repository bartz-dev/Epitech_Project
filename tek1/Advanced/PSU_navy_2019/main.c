/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** main.c
*/

#include "navy.h"

int init_navy(int ac, char **av)
{
    char **map = create_map(map);
    char **pos = NULL;
    char *buff = NULL;

    if (ac == 2) {
        buff = read_file(av[1]);
        save_pos(buff, &pos);
        if (init_server(map, pos) == -1)
            return -1;
    }
    if (ac == 3) {
        buff = read_file(av[2]);
        save_pos(buff, &pos);
        if (init_client(map, pos, my_getnbr(av[1])) == -1)
            return -1;
    }
    my_free_tab(pos);
    my_free_tab(map);
    return 0;
}

int main(int ac, char **av)
{
    receive[3] = 0;
    if (check_error(ac, av) == 1)
        return 84;
    if (init_navy(ac, av) == -1)
        return 84;
    return receive[3];
}