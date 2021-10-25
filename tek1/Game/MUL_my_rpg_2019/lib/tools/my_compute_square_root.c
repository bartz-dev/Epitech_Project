/*
** EPITECH PROJECT, 2019
** my_compute_square_root
** File description:
** Computes square root
*/

int my_compute_square_root(int nb)
{
    int i = -1;
    int result = 0;

    do {
        i++;
        result = i*i;
    }
    while (result < nb);
    if (result == nb)
        return (i);
    else
        return (0);
}

double sqrt(double nb)
{
    double min = 0;
    double max = nb;
    double moy;

    for (int i = 0; i < 1000; i++) {
        moy = (min + max) / 2;
        if (moy * moy == nb)
            return moy;
        if (moy * moy > nb)
            max = moy;
        else
            min = moy;
    }
    return moy;
}