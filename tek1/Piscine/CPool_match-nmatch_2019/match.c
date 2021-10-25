/*
** EPITECH PROJECT, 2019
** match
** File description:
** match by clement fleur
*/

int matchmatch(char *s1, char *s2)
{
    if (*s1 && *s2 && *s1 == *s2)
        return (match(s1 + 1, s2 + 1));
    if (!(*s1) && !(*s2))
        return (1);
    return (0);
}

int match(char *s1, char *s2)
{
    if (*s1 && *s2 == '*')
        return (match(s1, s2 + 1) || match(s1 + 1, s2));
    else if (!(*s1) && *s2 == '*')
        return (match(s1, s2 + 1));
    else
        matchmatch(s1, s2);
}
