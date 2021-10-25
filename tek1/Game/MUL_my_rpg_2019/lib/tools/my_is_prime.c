/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** Checks if a number is prime
*/

int can_divide_by(int a, int b)
{
    return (!(a%b));
}

int my_is_prime(int nb)
{
    int i;

    for (i = 2; i < nb; i++) {
        if (can_divide_by(nb, i) || nb == 1)
            return (0);
    }
    return (1);
}
