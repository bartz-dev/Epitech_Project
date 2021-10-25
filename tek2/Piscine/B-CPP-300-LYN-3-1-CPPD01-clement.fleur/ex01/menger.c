/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-clement.fleur
** File description:
** mengerinfo.c
*/

#include "menger.h"

vector_t get_coordinate(vector_t coordinate, menger_t menger_info,
    vector_pos_t pos)
{
    vector_t actual_coordinate  = {coordinate.x+(pos.x *
    menger_info.square_size), coordinate.y + (menger_info.square_size * pos.y)};

    return actual_coordinate;
}

void menger(vector_t coordinate, menger_config_t config, int level)
{
    menger_t menger_info;
    vector_pos_t pos = {0, 0};
    menger_info.square_size = (config.size / puissance(3, level))/3;

    menger_info.x = coordinate.x + menger_info.square_size;
    menger_info.y = coordinate.y + menger_info.square_size;
    printf("%.3d %.3d %.3d\n", menger_info.square_size,
    menger_info.x, menger_info.y);
    if (level + 1 == config.level) return;
    while (pos.x < 3) {
        if (pos.y >= 3) {
            pos.y = 0;
            pos.x++;
            continue;
        }
        if (pos.x == 1 && pos.y == 1)
            pos.y++;
        menger(get_coordinate(coordinate, menger_info, pos), config, level + 1);
        pos.y++;
    }
}