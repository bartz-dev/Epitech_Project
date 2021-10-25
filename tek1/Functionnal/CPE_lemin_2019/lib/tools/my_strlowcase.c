/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** my_strupcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}
