/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** ia.c
*/

#include "n4s.h"

void distrib(nfs_t *nfs)
{
    while (1) {
        nfs->arr = receive_str(nfs);
        if (get_speed(nfs->axis, nfs) == 1)
            break;
        nfs->arr = receive_str(nfs);
        if (check_dir(nfs->arr, nfs->axis, nfs) == 1)
            break;
    }
}

char **receive_str(nfs_t *nfs)
{
    char **arr;

    my_putstr(nfs->pos);
    nfs->cmd = get_next_line(0);
    check_pos(nfs->cmd, nfs);
    nfs->cmd = check_str(nfs->cmd);
    arr = my_strtotab(nfs->cmd, ':');
    nfs->axis = my_atof(arr[15]);
    return arr;
}

void init_struct(nfs_t *nfs)
{
    nfs->start = "start_simulation\n";
    nfs->pos = "get_info_lidar\n";
    nfs->stop = "stop_simulation\n";
    nfs->dir = "wheels_dir:";
}

int main(void)
{
    nfs_t nfs;
    init_struct(&nfs);

    get_pos(nfs.start, 0, &nfs);
    distrib(&nfs);
    return 0;
}

int check_management(float id, char *val, nfs_t *nfs)
{
    my_putstr("wheels_dir:");
    if (id < 0.0)
        my_putchar('-');
    my_putstr(val);
    val = get_next_line(0);
    if (check_pos(val, nfs) == 1)
        return (1);
    return (0);
}