/*
** EPITECH PROJECT, 2019
** my str cmp
** File description:
** compare two strings
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] || s2[i]; i++) {
        if (!s1[i] || !s2[i])
            return (-1 + 2 * !(s2[i]));
        if (s1[i] < s2[i] || s1[i] > s2[i])
            return (-1 + 2 * (s1[i] > s2[i]));
    }
    return 0;
}
