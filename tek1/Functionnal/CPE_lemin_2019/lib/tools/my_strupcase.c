/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
    return (str);
}
