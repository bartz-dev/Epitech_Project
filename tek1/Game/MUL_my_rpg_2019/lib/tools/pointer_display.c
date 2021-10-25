/*
** EPITECH PROJECT, 2019
** my_put_nbrp
** File description:
** my_put_nbrp
*/

#include "tools.h"
#include <stdlib.h>

int *pint(int i)
{
    int *p = malloc(sizeof(int));

    *p = i;
    return p;
}

double *pdouble(double i)
{
    double *p = malloc(sizeof(double));

    *p = i;
    return p;
}