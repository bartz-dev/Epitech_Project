/*
** EPITECH PROJECT, 2019
** BOO_phoenix_d02_2019
** File description:
** my_strstr.c
*/

#include "phoenix.h"

char *my_strstr(char *str, char const *to_find)
{
    int pos = 0;
    int counter = 0;

    while (counter < my_strlen(str)) {
        for (int pos2 = pos; str[pos2] == to_find[counter];pos2++) {
            if (to_find[pos2] == '\0')
                return (&str[pos]);
            counter++;
        }
        pos++;
    }
    return (0);
}