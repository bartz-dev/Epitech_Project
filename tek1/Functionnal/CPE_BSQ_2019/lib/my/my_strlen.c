/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** Gives string length
*/

int my_strlen(char const *str)
{
    int length;

    length = 0;
    while (str[length]) {
        length++;
    }
    return (length);
}
