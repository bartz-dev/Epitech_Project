/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Gives string length
*/

int my_strlen(char const *str)
{
    int len;

    for (len = 0; str[len]; len++);
    return len;
}
