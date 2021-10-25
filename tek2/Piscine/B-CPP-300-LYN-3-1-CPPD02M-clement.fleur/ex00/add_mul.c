/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-clement.fleur
** File description:
** add_mul.c
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int firstValue = *first;
    int secondeValue = *second;

    *first = firstValue + secondeValue;
    *second = firstValue * secondeValue;
}