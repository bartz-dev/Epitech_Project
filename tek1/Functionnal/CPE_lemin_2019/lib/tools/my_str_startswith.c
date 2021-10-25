/*
** EPITECH PROJECT, 2019
** my_str_startswith
** File description:
** my_str_startswith
*/

#include "tools.h"

int my_str_startswith(char *haystack, char *needle)
{
    for (int i = 0; needle[i]; i++)
        if (needle[i] != haystack[i])
            return 0;
    return 1;
}