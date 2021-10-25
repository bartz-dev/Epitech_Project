/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** by clement fleur
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int calculate(char **argv)
{
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int checka;
    int i;

    while (a <= b) {
        checka = a;
        if (checka % 3 == 0 && checka % 5 != 0)
            printf("Fizz\n");
        if (checka % 5 == 0 && checka % 3 != 0)
            printf("Buzz\n");
        if (checka % 3 == 0 && checka % 5 == 0)
            printf("FizzBuzz\n");
        checka % 3 != 0 && checka % 5 != 0 ? printf("%d\n", a) : i++;
        a++;
    }
    return 0;
}

int check_error(char **argv, int ac)
{
    if (ac <= 2)
        return 84;
    else if (atoi(argv[1]) > atoi(argv[2])) {
        write(2, "Error: the second parameter must be ", 36);
        write(2, "greater than the first one.\n", 28);
        return 84;
    }
    return 0;
}

int main(int ac, char **argv)
{
    if (check_error(argv, ac) == 84)
        return 84;
    return calculate(argv);
}
