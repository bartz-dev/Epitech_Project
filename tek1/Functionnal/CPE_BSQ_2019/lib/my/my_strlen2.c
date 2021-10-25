/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** To calcul \n number in a string
*/

int my_strlen_nbligne(char const *str)
{
    int	i;
    int	line;

    line = 0;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            line = line + 1;
        i = i + 1;
    }
    if (str[i - 1] == '\n')
        line = line - 1;
    return (line);
}
