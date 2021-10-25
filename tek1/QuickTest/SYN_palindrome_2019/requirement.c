/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** requirement.c
*/

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    else if (nb == 0)
        return 1;
    else
        return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis(int nb)
{
    int root = 0;

    if (nb < 0)
        return (-1);
    if (nb == 0 || nb == 1)
        return (nb);
    for (root = root; root < 46341 && root < nb + 1; root++)
        if (root * root == nb)
            return (root);
    return (-1);
}