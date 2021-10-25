/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** task03 day 06 by clement fleur
*/

int my_strlen(char const *str)
{
    int i = 0;
    int len = 0;

    while (str[i] != '\0') {
        i++;
        len = len + 1;
    }
    return (len);
}

char *my_revstr(char *str)
{
    int  count = my_strlen(str) - 1;
    int i = 0;
    char p;
    int size = my_strlen(str);

    while (i < (size / 2)) {
        p = str[count];
        str[count] = str[i];
        str[i] = p;
        count--;
        i++;
    }
    return (str);
}
