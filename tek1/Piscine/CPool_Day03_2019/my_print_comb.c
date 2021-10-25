/*
** EPITECH PROJECT, 2019
** my_print_comb
** File description:
** 
*/

int my_print_number(int nbr)
{
    int a;
    int b;
    int c = nbr / 100;
    int z = nbr;

    nbr = nbr % 100;
    b = nbr / 10;
    nbr = nbr % 10;
    a = nbr;
    if (a <= b)
        return (-1);
    if (b <= c)
        return (-1);
    return (z);
}

void check_nbr(int i)
{
    if (i < 789) {
        my_putchar(',');
        my_putchar(' ');
    }
    else{
        my_putchar('\n');
    }
}

int my_print_comb(void)
{
    int i;
    int nbr;

    for (i = 0; i < 1000; i++) {
        nbr = my_print_number(i);
        if (nbr != -1) {
            my_putchar((nbr / 100) + 48);
            nbr = nbr % 100;
            my_putchar((nbr / 10) + 48);
            my_putchar((nbr % 10) + 48);
            check_nbr(i);
        }
    }
}
