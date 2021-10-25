/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int nbr = 1;

    if (nb <= 1)
        return 0;
    while (nbr * nbr != nb) {
        nbr++;
        if (nb == nbr * nbr)
            return nbr;
        if (nbr == nb)
            return 0;
    }
}
