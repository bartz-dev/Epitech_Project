/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** 
*/

#include <stdlib.h>
#include "rush3.h"
#include <stdio.h>

char *my_strdup(char const *src)
{
    int i;
    char *dest;
    
    i = 0;
    while (src[i] != '\0') {
        i++;
    }
    dest = malloc(sizeof(char) * (i + 1));
    my_strcpy(dest, src);
    return dest;
}
