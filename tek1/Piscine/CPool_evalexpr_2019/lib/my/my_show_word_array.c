/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** task03 by clement fleur
*/

#include "expr.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != 0) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}
