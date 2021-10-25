/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** Swaps 2 variables
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
