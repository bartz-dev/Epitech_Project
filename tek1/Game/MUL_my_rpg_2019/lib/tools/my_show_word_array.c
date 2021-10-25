/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** my_show_word_array
*/

#include "tools.h"

int my_show_word_array(char * const *arr)
{
    int i = 0;

    while (arr[i]) {
        my_putstr(arr[i]);
        my_putchar('\n');
        i++;
    }
    return (0);
}
