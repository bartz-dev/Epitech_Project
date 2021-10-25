/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** task05 by clement fleur
*/

int my_find_prime_sup(int nb)
{
    int nb2 = 0;

    for (nb2 = nb; my_is_prime(nb2) != 1; nb2++);
    return nb2;
}
