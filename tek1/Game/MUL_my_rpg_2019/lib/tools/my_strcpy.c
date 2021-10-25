/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** Copies a string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i]; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
