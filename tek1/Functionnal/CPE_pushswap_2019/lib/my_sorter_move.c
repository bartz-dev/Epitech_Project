/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_sorter_move.c
*/

#include "pushswap.h"

int remove_first(int *arr, int len)
{
    int i = 0;
    int first;

    for (i = 0; i < len && arr[i] != -1; i++)
        if (i > 0)
            arr[i - 1] = arr[i];
        else
            first = arr[i];
    arr[i - 1] = -1;
    return (first);
}

void add_to(int *arr, int value, int order, int len)
{
    int i = 1;
    int tmp = arr[0];
    int tmp2 = 0;

    if (order == 0) {
        for (i = 1; i < len; i++) {
            tmp2 = arr[i];
            arr[i] = tmp;
            tmp = tmp2;
        }
        arr[0] = value;
    }
    else {
        for (i = 0; arr[i] != -1; i++);
        arr[i] = value;
    }
}
