/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_putnprintable.c
*/

#include "navy.h"

int my_char_isprintable(char str)
{
    if (str == '\0')
        return 0;
    if (str >= 0 && str <= 31)
        return 0;
    else
        return 1;
}

void my_putnprintable(char const *str)
{
    int a = 0;

    for (int i = 0; str[a] != '\0'; a++) {
        i = str[a];
        if (my_char_isprintable(str[a]) == 0) {
            my_putchar(92);
            if (i < 8)
                my_putchar('0');
            my_putchar('0');
            base(i, 8);
            a++;
        }
        if (str[a] == 127) {
            my_putchar(92);
            base(i, 8);
            a++;
        }
        my_putchar(str[a]);
    }
}