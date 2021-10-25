/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD01-clement.fleur
** File description:
** menger.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


typedef struct menger_s
{
    int x;
    int y;
    int xbase;
    int ybase;
    int square_size;
    int size;
    int level;
} menger_t;

typedef struct menger_config_s
{
    int size;
    int level;
} menger_config_t;

typedef struct vector_s
{
    int x;
    int y;
} vector_t;

typedef struct vector_pos_s
{
    int x;
    int y;
} vector_pos_t;


void menger(vector_t coordinate, menger_config_t config, int level);
vector_t get_coordinate(vector_t coordinate, menger_t mengerinfo,
vector_pos_t pos);
int puissance(int base, int x);
int error_handling(int ac, int ordinate, char *levels);
int writeCoordinate(menger_t *menger);
void checkMiddle(menger_t *menger);