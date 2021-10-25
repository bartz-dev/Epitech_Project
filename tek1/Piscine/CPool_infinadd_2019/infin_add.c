/*
** EPITECH PROJECT, 2019
** infindadd
** File description:
** addition by clement fleur
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *my_revstr(char *str);
int my_strlen(char const *str);

int check_result(char *sum, char *term, int result, int diz, int i)
{
    if (sum[i] == '\0' && term[i] != '\0') {
            sum[i] = '0';
            sum[i + 1] = '\0';
        }
        if (sum[i] != '\0' && term[i] == '\0') {
            term[i] = '0';
            term[i + 1] = '\0';
        }
        result = (sum[i] - 48) + (term[i] - 48) + diz;
        return result;
}

int infin_add(char **av[], char *res, int result)
{
    char *sum = my_revstr(av[1]);
    char *term = my_revstr(av[2]);
    int diz = 0;
    int i = 0;

    for (i = 0; sum[i] != '\0' || term[i] != '\0'; i++) {
        diz = 0;
        result = check_result(sum, term, result, diz, i);
        if (result > 9) {
            result = result % 10;
            diz = 1;
            res[i + 1] = diz + 48;
        }
        res[i] = result + 48;
    }
    if (diz != 0)
        res[i] = diz + 48;
    my_revstr(res);
    my_putstr(res);
    my_putchar('\n');
    return 0;
}

int main(int ac, char **av[])
{
    int put1 = my_strlen(av[1]);
    int put2 = my_strlen(av[2]);
    int *result;

    if (ac > 2) {
        result = malloc(sizeof(int)* (put1 + put2));
        infin_add(av, result, 0);
    }
    else
        return 84;
    return 0;
}
