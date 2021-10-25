/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** 
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int p = 0;
    char *newstr;

    newstr = malloc(sizeof(char) * (6 + nb));
    while (dest[i++] != 0);
    newstr = dest;
    while (p != nb) {
        newstr[i - 1] = src[p];
        p++;
        i++;
    }
    newstr[i - 1] = 0;
    return newstr;
}