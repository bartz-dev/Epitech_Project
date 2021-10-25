/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** Finds superior prime
*/

#include "tools.h"

int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
