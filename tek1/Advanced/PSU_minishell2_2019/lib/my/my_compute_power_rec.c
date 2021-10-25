/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int  count;

    if (p == 0)
        return 1;
    else if (p == 1)
        return nb;
    if (p < 0)
        return 0;
    else
        count = my_compute_power_rec(nb, p - 1) * nb;
    return count;
}
