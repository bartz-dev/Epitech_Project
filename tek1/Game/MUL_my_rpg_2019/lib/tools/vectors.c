/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** vectors
*/

#include "tools.h"

vector2i_t v2i(int x, int y)
{
    vector2i_t v;

    v.x = x;
    v.y = y;
    return v;
}

vector2f_t v2f(float x, float y)
{
    vector2f_t v;

    v.x = x;
    v.y = y;
    return v;
}

vector3i_t v3i(int x, int y, int z)
{
    vector3i_t v;

    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

vector3f_t v3f(float x, float y, float z)
{
    vector3f_t v;

    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}