/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** palindromic.c
*/

#include "../include/my.h"
#include "../include/palindrome.h"

int palindromic(palindrome *pal)
{
    int p = 1;
    int nb = 0;
    int new_nbr = pal->number;
    char *nbrs = malloc(sizeof(char) * 100);
    char *nbrss = malloc(sizeof(char) * 100);


    if (reverse_nbr(pal->number, pal) == pal->number && pal->imin == 0)
            print_result(pal->number, pal, 0, 0);
    new_nbr = reverse_nbr(pal->number, pal);
    nb = new_nbr;
    for (p = p; p < pal->imax; p++) {
        new_nbr = reverse_nbr(nb, pal);
        nb += new_nbr;
        if ((my_strcmp(my_revstr(baseconv(nbrs, nb, pal->base)), baseconv(nbrss,
            nb, pal->base)) == 1) && (pal->imin <= p))
            return print_result(pal->number, pal, nb, p);
    }
    return 0;
}