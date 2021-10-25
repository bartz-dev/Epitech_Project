/*
** EPITECH PROJECT, 2019
** my_xor
** File description:
** my_xor
*/

int xor(int cond1, int cond2)
{
    return (cond1 || cond2) && !(cond1 && cond2);
}
