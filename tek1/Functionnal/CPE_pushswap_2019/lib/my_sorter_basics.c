/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_sorter_basics.c
*/

#include "pushswap.h"

void swap(int *arr, char c, struct req *req)
{
    int tmp = arr[0];

    arr[0] = arr[1];
    arr[1] = tmp;
    my_put_char('s');
    my_put_char(c);
    end_instruction(req);
}

void push(int *arr, int *arr2, struct req *req, char c)
{
    int value = remove_first(arr, req->len);

    add_to(arr2, value, 0, req->len);
    my_put_char('p');
    my_put_char(c);
    end_instruction(req);
}
