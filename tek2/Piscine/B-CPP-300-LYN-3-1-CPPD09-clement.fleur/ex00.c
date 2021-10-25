/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-clement.fleur
** File description:
** ex00.c
*/

#include "ex00.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

static void cthulhu_initializer(cthulhu_t *this)
{
    printf("----\n");
    this->m_power = 42;
    this->m_name = "Cthulhu";
    printf("Building %s\n", this->m_name);
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new_object = malloc(sizeof(cthulhu_t));
    cthulhu_initializer(new_object);

    return new_object;
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void sleeping(cthulhu_t *this)
{
    this->m_power += 42000;
    printf("%s sleeps\n", this->m_name);
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    printf("----\n");
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent.m_name = strdup(_name);
    if (_is_A_Legend == 1)
        this->m_parent.m_power = 42;
    else
        this->m_parent.m_power = 0;
    printf("Building Cthulhu\n");
    printf("Building %s\n", this->m_parent.m_name);
}


koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new_object =  malloc(sizeof(koala_t));
    koala_initializer(new_object, name, is_a_legend);

    return new_object;
}

void eat(koala_t *this)
{
    this->m_parent.m_power += 42;
    printf("%s eats\n", this->m_parent.m_name);
}