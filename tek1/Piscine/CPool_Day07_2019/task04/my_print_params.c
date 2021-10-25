/*
** EPITECH PROJECT, 2019
** my_print_params
** File description:
** task04 Day07
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    
    while (i < argc)
    {
        my_putstr(argv[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
