/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** eval_expr.c
*/

#include "expr.h"

int parseint(char **ps, int nbr)
{
    int signe;

    nbr = 0;
    signe = 1;
    if ((*ps)[0] == '+' || (*ps)[0] == '-') {
        if ((*ps)[0] == '-')
            signe = -1;
        *ps = *ps + 1;
    }
    if ((*ps)[0] == '(') {
        *ps = *ps + 1;
        nbr = check(ps);
        if ((*ps)[0] == ')')
            *ps = *ps + 1;
        return (signe * nbr);
    }
    while('0' <= (*ps)[0] && (*ps)[0] <= '9') {
        nbr = (nbr * 10) + (*ps)[0] - '0';
        *ps = *ps + 1;
    }
    return (signe * nbr);
}

int check(char **ps)
{
    int lhs;
    int rhs;
    char op;
    int nbr;

    lhs = parseint(ps, nbr);
    while ((*ps)[0] != '\0' && (*ps)[0] != ')') {
        op = (*ps)[0];
        *ps = *ps + 1;
        if (op == '+' || op == '-')
            rhs = operator(ps);
        else
            rhs = parseint(ps, nbr);
        lhs = do_op(lhs, rhs, op);
    }
    return (lhs);
}

int operator(char **ps)
{
    int lhs;
    int rhs;
    char op;
    int nbr;

    lhs = parseint(ps, nbr);
    while ((*ps)[0] == '*' || (*ps)[0] == '/' || (*ps)[0] == '%') {
        op = (*ps)[0];
        *ps = *ps + 1;
        rhs = parseint(ps, nbr);
        lhs = do_op(lhs, rhs, op);
    }
    return (lhs);
}

int eval_expr(char *str)
{
    str = suppr_spaces(str);
    if (str[0] == '\0')
        return (0);
    return (check(&str));
}

int main(int ac, char **av)
{
    if (ac > 1) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
    }
    return (0);
}  
