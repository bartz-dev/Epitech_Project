/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** palindrome.c
*/

#include "../include/palindrome.h"
#include "../include/my.h"

int print_result(int nb, palindrome *pal, int p, int origin)
{
    my_put_nbr(nb);
    my_putstr(" leads to ");
    my_put_nbr(p);
    my_putstr(" in ");
    my_put_nbr(origin);
    my_putstr(" iteration(s) in base ");
    my_put_nbr(pal->base);
    my_putchar('\n');
    return 1;
}

int calculate_iterative(int i, palindrome *pal)
{
    int p = 0;
    int nb = i;
    int new_nbr = 0;
    char *nbrs = malloc(sizeof(char) * 100);
    char *nbrss = malloc(sizeof(char) * 100);
    int checker = 0;

    if (reverse_nbr(i, pal) == pal->number && pal->imin == 0)
            checker = print_result(i, pal, pal->number, p + 1);
    while (p < pal->imax) {
        new_nbr = reverse_nbr(nb, pal);
        nb += new_nbr;
        if ((my_strcmp(baseconv(nbrs, nb, pal->base),baseconv(nbrss,
            pal->number, pal->base)) == 1) && (pal->imin <= p + 1))
            checker = print_result(i, pal, pal->number, p + 1);
        p++;
    }
    free(nbrs);
    free(nbrss);
    return checker;
}

int palind(palindrome *pal)
{
    int checker = 0;

    for (int i = 1; i <= pal->number; i++) {
        if (checker == 0)
            checker = calculate_iterative(i, pal);
        else
            calculate_iterative(i, pal);
    }
    return checker;
}

int reverse_nbr(int nb, palindrome *pal)
{
    int nbr = nb;
    int lastdigit = 0;
    int reverse = 0;
    int i = 0;

    while (nbr > 0) {
        lastdigit = nbr % pal->base;
        reverse = (reverse * pal->base) + lastdigit;
        nbr = nbr / pal->base;
        i++;
    }
    return reverse;
}