/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** my_string.c
*/

#include "pushswap.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return (s1[i] - s2[i]);
}

int my_atoi(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '-' || str[i] == '+')
            continue;
        if (str[i] >= '0' && str[i] <= '9')
        {
            nbr *= 10;
            nbr += str[i] - '0';
        }
        else if(nbr != 0)
            break;
        else
            return (0);
    }
    if (str[0] == '-')
        nbr *= -1;
    return (nbr);
}

int my_str_isnum(const char *str)
{
    const int true = 1;
    const int false = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && (str[i] == '-' || str[i] == '+'))
            continue;
        if (!(str[i] <= '9' && str[i] >= '0'))
            return (false);
    }
    return (true);
}
