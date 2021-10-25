/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int nbr = nb;

    if (p == 0)
        return (1);
    if (p > 0) {
        while (p > 1) {
            nbr = nbr * nb;
            p--;
        }
        return (nbr);
    }
    return (0);
}
