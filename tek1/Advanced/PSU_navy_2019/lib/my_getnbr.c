/*
** EPITECH PROJECT, 2019
** my_getnb
** File description:
** lib - mehdi.zehri
*/

#include "navy.h"

int neg(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i - 1] == '-')
            return 1;
        i++;
    }
    return 0;
}

int my_getnbr(char *str)
{
    int i = 0;
    int a = 0;
    int compt = 10;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            a = a * 10;
            a = a + (str[i] - 48);
        }
        if (str[i] < '0' || str[i] > '9') {
            if (str[i - 1] >= '0' && str[i -1] <= '9')
                break;
        }
        i++;
    }
    if (neg(str) == 1)
        a = a * (-1);
    return (a);
}
