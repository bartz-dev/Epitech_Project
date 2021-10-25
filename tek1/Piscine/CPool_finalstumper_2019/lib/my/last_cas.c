/*
** EPITECH PROJECT, 2019
** last_cas
** File description:
** 
*/

void last_cas(char *buff, int x, int y, int j)
{
    if (buff[0] == 'A' && buff[x - 1] == 'C' && buff[j - 2] == 'A') {
        my_putstr("[rush1-5]");
        my_putchar (' ');
        my_put_nbr(x);
        my_putchar (' ');
        my_put_nbr(y);
    }
}

void cas1(char *buff, int x, int y)
{
    int j = 0;

    if (buff[0] == 'A' && buff[x - 1] == 'A') {
        my_putstr("[rush1-3]");
        my_putchar (' ');
        my_put_nbr(x);
        my_putchar (' ');
        my_put_nbr(y);
    }
    while (buff[j] != '\0')
        j++;
    if (buff[0] == 'A' && buff[x - 1] == 'C' && buff[j - 2] == 'C') {
        my_putstr("[rush1-4]");
        my_putchar (' ');
        my_put_nbr(x);
        my_putchar (' ');
        my_put_nbr(y);
    }
    else
        last_cas(buff, x, y, j);
} 
