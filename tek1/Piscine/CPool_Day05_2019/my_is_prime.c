/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** task06 by clement fleur
*/

int my_is_prime(int nb)
{
    int div_count = 2;
    int check;

    if (nb <= 0)
        return 0;
    if (nb == 1)
        return 0;
    while (div_count != nb) {
        check = nb % div_count;
        div_count++;
        if (check == 0) {
            return 0;
        }
    }
    return 1;
}
