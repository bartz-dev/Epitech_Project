/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_engine.c
*/

#include "pushswap.h"

void serial(int ac, char **as, struct req *req)
{
    if (req->stat == 1)
        ac--;
    req->len = ac - 1;
    req->list_a = malloc(sizeof(int) * req->len);
    req->list_b = malloc(sizeof(int) * req->len);

    for (int i = 1; i < ac; i++)
        req->list_a[i - 1] = my_atoi(as[i]);
    for (int i = 0; i < ac - 1; i++)
        req->list_b[i] = -1;
}

void process(struct req *req)
{
    while (1) {
        if (req->list_a[0] > get_last(req->list_a, req->len))
            rotate(req->list_a, req, 'a');
        if (req->list_a[0] > req->list_a[1])
            swap(req->list_a, 'a', req);
        req->sorted_a = list_sorted(req);
        if (req->sorted_a == 0 &&
            (req->list_a[0] < req->list_a[1])) {
            push(req->list_a, req->list_b, req, 'b');
            clean(req);
        }
        while (req->sorted_a == 1) {
            if (req->sorted_a == 1 && req->list_b[0] == -1)
                break;
            push(req->list_b, req->list_a, req, 'a');
            req->sorted_a = list_sorted(req);
        }
        if (req->sorted_a == 1 && req->list_b[0] == -1)
            break;
    }
}

void clean(struct req *req)
{
    if (req->list_b[1] != -1) {
        if (req->list_b[0] < get_last(req->list_b,
            req->len))
            rotate(req->list_b, req, 'b');
        if (req->list_b[0] < req->list_b[1])
            swap(req->list_b, 'b', req);
    }
}

void display_order(struct req *req)
{
    if (req->stat == 0)
        return;
    my_put_char('\n');
    for (int i = 0; i < req->len; i++) {
        my_put_nbr(req->list_a[i]);
        if (i + 1 < req->len)
            my_put_char(' ');
    }
    my_put_char('\n');
    for (int i = 0; i < req->len; i++) {
        my_put_nbr(req->list_b[i]);
        if (i + 1 < req->len)
            my_put_char(' ');
    }
}
