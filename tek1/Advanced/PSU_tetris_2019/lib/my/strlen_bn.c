/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** strlen for aknoledge
*/

#include <stdio.h>
#include "my.h"

int my_strlenbn(char *str)
{
    int i = 0;
    int	p = 0;

    while (str[i] != '\n') {
        i = i + 1;
        p = p + 1;
    }
    i = i + 1;
    p = p + 1;
    while (str[i] != '\n' && str[i] != '\0')
        i = i + 1;
    return (i - p);
}
