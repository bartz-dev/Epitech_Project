/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** 
*/

int my_strlen2(char const *str)
{
    int i = 0;
    int p = 0;
    
    while (str[i] != '\0') {
        if (str[i] == '\n')
            p++;
        i++;
    }
    return p;
}
