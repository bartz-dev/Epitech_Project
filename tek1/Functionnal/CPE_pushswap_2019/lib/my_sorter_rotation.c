/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_sorter_rotation.c
*/

#include "pushswap.h"

void rotate(int *arr, struct req *req, char c)
{
    int first_entry = remove_first(arr, req->len);

    add_to(arr, first_entry, req->len, req->len);
    my_put_char('r');
    my_put_char(c);
    end_instruction(req);
}
