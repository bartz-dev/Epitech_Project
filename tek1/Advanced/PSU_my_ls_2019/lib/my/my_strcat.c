/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** by clement fleur
*/

int m_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
  return (i);
}

char *my_strcat(char *dest, char *src)
{
    int i = m_strlen(dest);
    int j = 0;

    while (src[j] != '\0')
      dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}
