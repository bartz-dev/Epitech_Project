/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec
** File description:
** task02
*/

int my_compute_factorial_rec(int nb)
{
    int count;

    if (nb < 0) || (nb > 12) 
        return 0;
    else if (nb == 1) || (nb == 0)
        return (1);
    else
        count = my_compute_factorial_rec(nb - 1) * nb;
    return count;
}
