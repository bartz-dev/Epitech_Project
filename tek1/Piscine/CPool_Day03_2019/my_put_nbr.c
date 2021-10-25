/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** 
*/

int loops(int nb) {
    long rev =  0;
    int number = 0;

    while (nb > 0) {
        number = nb % 10;
        rev = rev * 10 + number;
        nb = nb / 10;
    }
    while (rev > 0) {
        number = rev % 10;
        if (number == 0) {
            number = number + 48 ;
        }
        my_putchar(number + 48);
        rev = rev / 10;
    }

}

int my_put_nbr (int nb)
{
    long rev = 0;
    int number = 0;

    if (nb == 0) {
        my_putchar('0');
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb*(-1);
    }
    loops(nb);
}
