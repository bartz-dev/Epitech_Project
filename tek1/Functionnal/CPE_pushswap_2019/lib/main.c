/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** main.c
*/

#include "pushswap.h"

int main(int ac, char **as)
{
    struct req *req = get_request();

    check(ac, as, req);
    if (ac > 2) {
        serial(ac, as, req);
        if (list_sorted(req) == 1 || req->len > 2300) {
            my_put_char('\n');
            return (0);
        }
        process(req);
        if (req->stat == 0)
            my_put_char('\n');
        return (0);
    }
    my_put_char('\n');
    return (0);
}

void check(int ac, char **as, struct req *req)
{
    if (ac <= 2)
        return;
    else if (my_strcmp(as[ac - 1], "-v") == 0 ||
        my_strcmp(as[ac - 1], "-V") == 0)
    	req->stat = 1;
}