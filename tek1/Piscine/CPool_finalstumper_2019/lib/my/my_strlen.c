/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** 
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return i;
}
