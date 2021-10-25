/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** my_strcmp.c
*/

#include "n4s.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] && s2[i] && s1[i] == s2[i])
        i += 1;
    return (s1[i] - s2[i]);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i += 1;
    return (i);
}

float my_atof(char *str)
{
    float nb = 0.0;
    int i = 0;
    int id = 0;

    while (str[id] != 0 && str[id] >= '0' && str[id] <= '9')
        nb = nb * 10.0 + (str[id++] - 48);
    id += 1;
    if (str[id] == '.') {
        while (str[id] != 0) {
            nb = nb * 10.0 + (str[id] - 48);
            i -= 1;
        }
    }
    while (i++ < 0)
        nb *= 0.1;
    return (nb);
}
