/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_get.c
*/

#include "pushswap.h"

struct req* get_request()
{
    struct req *req = malloc(sizeof(struct req));

    req->stat = 0;
    req->sorted_a = 0;
    req->sorted_b = 0;
    return (req);
}
