/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {}
    return i;
}