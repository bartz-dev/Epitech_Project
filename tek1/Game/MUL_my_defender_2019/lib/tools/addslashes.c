/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** addslashes
*/

#include <stdlib.h>
#include "tools.h"

char *addslashes(char *str)
{
    int count = 0;
    int i;
    char *new_str;

    for (i = 0; str[i]; i++)
        if (str[i] == '\\' || str[i] == '"') count++;
    new_str = malloc(sizeof(char) * (my_strlen(str) + count + 1));
    count = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] == '\\' || str[i] == '"') {
            new_str[i + count] = '\\';
            count++;
            new_str[i + count] = str[i];
        } else new_str[i + count] = str[i];
    }
    new_str[i + count] = 0;
    return new_str;
}