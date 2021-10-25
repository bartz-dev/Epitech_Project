/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Finds first occurence of a string inside another string
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    char *starting = 0;

    while (str[i]) {
        if (!to_find[j]) {
            return (starting);
        } else if (str[i] == to_find[j]) {
            starting = starting ? starting : str + i;
            j++;
        } else {
            starting = 0;
            j = 0;
        }
        i++;
    }
    if (starting && to_find[j])
        return (0);
    return (starting);
}