/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int sqrt = 0;

    if ((nb == 0) || (nb < 0)) {
        return 0;
    }
    if (nb == 1) {
        return 1;
    }
    while (sqrt * sqrt != nb) {
        sqrt++;
        if (sqrt * sqrt > nb) {
            return 0;
        }
    }
    return sqrt;
}
