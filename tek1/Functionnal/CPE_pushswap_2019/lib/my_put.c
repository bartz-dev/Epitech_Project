/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_put.c
*/

#include "pushswap.h"

void my_put_array(int len, int *arr)
{
    int i = 0;

    for (i = 0; i < len; i++) {
        my_put_nbr(arr[i]);
        my_put_char(' ');
    }
    my_put_char('\n');
}
