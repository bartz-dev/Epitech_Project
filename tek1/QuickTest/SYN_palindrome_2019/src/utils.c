/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** utils.c
*/

#include <unistd.h>
#include "../include/my.h"

char *baseconv(char *string, int nbr, int base)
{
    int count;
    char alpha[11] = "0123456789";

    for (count = 0; nbr != 0; count++) {
        string[count] = alpha[nbr % base];
        nbr = nbr / base;
    }
    string[count] = '\0';
    return string;
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] == s2[i]; i++)
        if (s1[i] == '\0' && s2[i] == '\0')
            return (1);
    return (0);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != 0) {
        write(1, &str[i], 1);
        i++;
    }
}

void my_put_nbr(int nb)
{
    char sign = '-';

    if (nb > 9)
        my_put_nbr(nb / 10);
    else if (nb < 0) {
        nb *= -1;
        write(1, &sign, 1);
        my_put_nbr(nb / 10);
    }
    sign = '0' + nb % 10;
    write(1, &sign, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != 0)
        i++;
    return i;
}