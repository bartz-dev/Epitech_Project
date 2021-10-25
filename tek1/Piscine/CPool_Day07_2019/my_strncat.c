/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** my_strncat
*/

char *my_strncat(char *dest , char const *src, int nb)
{
    int i = 0;
    int p = 0;

    while (dest[p] != '\0')
        p++;
    while (i <= nb - 1) {
        dest[p] = src[i];
        i++;
        p++;
    }
    dest[p] = '\0';
    return (dest);
}
