/*
** EPITECH PROJECT, 2020
** libtools
** File description:
** my_str_endswith
*/

#include "tools.h"

int my_str_endswith(char *str, char *with)
{
    int diff = my_strlen(str) - my_strlen(with);

    if (diff < 0) return 0;
    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        if (str[i] != with[i - diff])
            return 0;
        if (i - diff == 0)
            return 1;
    }
    return 1;
}