/*
** EPITECH PROJECT, 2019
** my_arrlen.c
** File description:
** my_arrlen
*/

int my_arrlen(char **arr)
{
    int i = 0;
    while (arr[i])
        i++;
    return (i);
}
