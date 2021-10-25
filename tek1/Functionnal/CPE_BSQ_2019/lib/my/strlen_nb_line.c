/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** count string and check hhow many aknoledge
*/

#include "my.h"

int my_strnbline(char *str)
{
    int	i;
    int	p;

    p = 0;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            p = p + 1;
        i = i + 1;
    }
    if (str[i - 1] == '\n')
        p = p - 1;
    return (p);
}
