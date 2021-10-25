/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** task01
*/

int my_compute_factorial_it(int nb)
{
    int count = 1;
    
    if ((nb > 12) || (nb < 0))
        return 0;
    if ((nb == 0) || (nb == 1))
        return 1;
    while (nb > 0) {
        count = count * nb;
        nb--;
    }
    return count;
}
