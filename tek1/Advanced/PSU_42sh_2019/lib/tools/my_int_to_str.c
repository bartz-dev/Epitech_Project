/*
** EPITECH PROJECT, 2019
** my_int_to_str
** File description:
** my_int_to_str
*/

#include "tools.h"
#include <stdlib.h>

char **int_to_str(int nb, char **str)
{
    char s[2];
    char **s2 = malloc(sizeof(char *));

    if (nb < -2147483647) {
        *s2 = my_strdup("-2147483648");
        return s2;
    }
    if (nb < 0) {
        nb = nb * -1;
        *str = my_strconcat(*str, "-");
    } else if (nb >= 10) {
        int_to_str(nb / 10, str);
        int_to_str(nb % 10, str);
    } else {
        s[0] = nb + '0';
        s[1] = 0;
        *str = my_strconcat(*str, s);
    }
    return (str);
}

char *my_int_to_str(int nb)
{
    char **str = malloc(sizeof(char *));
    char **output;
    char *nbr;

    *str = my_strdup("");
    output = int_to_str(nb, str);
    nbr = *output;
    free(output);
    return nbr;
}