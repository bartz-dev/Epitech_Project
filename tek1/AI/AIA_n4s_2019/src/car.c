/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** car.c
*/

#include "n4s.h"

int get_speed(float line, nfs_t *nfs)
{
    int i = line;

    i >= 2100 ? get_pos("car_forward:1.0\n", 0, nfs) :
    i >= 1600 ? get_pos("car_forward:0.7\n", 0, nfs) :
    i >= 1100 ? get_pos("car_forward:0.5\n", 0, nfs) :
    i >= 700 ? get_pos("car_forward:0.4\n", 0, nfs) :
    i >= 300 ? get_pos("car_forward:0.2\n", 0, nfs) :
    get_pos("car_forward:0.1\n", 0, nfs);
    return (i);
}

int check_dir(char **tab, float line, nfs_t *nfs)
{
    float right = my_atof(tab[31]);
    float left = my_atof(tab[1]);
    int i = line;

    i >= 1200 ? check_management(left - right, "0.005\n", nfs) :
    i >= 1000 ? check_management(left - right, "0.050\n", nfs) :
    i >= 600 ? check_management(left - right, "0.1\n", nfs) :
    i >= 400 ? check_management(left - right, "0.2\n", nfs) :
    i >= 200 ? check_management(left - right, "0.3\n", nfs) :
    i >= 100 ? check_management(left - right, "0.4\n", nfs) :
    check_management(left - right, "0.5\n", nfs);
    return (i);
}