/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

#include "tools.h"

char *my_revstr(char *str)
{
    int i;
    char temp;
    int len = my_strlen(str);

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return (str);
}
