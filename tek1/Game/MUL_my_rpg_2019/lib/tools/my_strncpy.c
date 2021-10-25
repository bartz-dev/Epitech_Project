/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Copies n characters from a string
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    int string_ended = 0;

    for (i = 0; i < n; i++) {
        string_ended = string_ended ? 1 : !src[i];
        dest[i] = !string_ended ? src[i] : '\0';
    }
    return dest;
}
