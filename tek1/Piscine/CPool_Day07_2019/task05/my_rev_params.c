/*
** EPITECH PROJECT, 2019
** my_rev_params
** File description:
** task 05 day07
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
    while (argc != 0) {
        my_putstr(argv[argc - 1]);
        my_putchar('\n');
        argc--;
    }
    return 0;
}
