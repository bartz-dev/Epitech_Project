/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_sorter.c
*/

#include "pushswap.h"

int list_sorted(struct req *req)
{
    int i;

    for (i = 1; i < req->len && req->list_a[i] != -1; i++) {
        if (req->list_a[i - 1] <= req->list_a[i])
            continue;
        else
            return (0);
    }
    return (1);
}

int get_last(int *arr, int len)
{
    int i;

    for (i = len - 1; i > 0; i--)
        if (arr[i] != -1)
            return (arr[i]);
    return (-1);
}

void end_instruction(struct req *req)
{
    display_order(req);
    if (req->stat == 1)
        my_put_char('\n');
    else if (!(list_sorted(req) == 1 && req->list_b[0] == -1))
        my_put_char(' ');
}
