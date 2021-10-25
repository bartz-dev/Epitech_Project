/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** task02 by clement fleur
*/

int my_putchar(char c);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

   while(src[i] != src[n]) {
       dest[i] = src[i];
        i++;
    }
   return dest;
}
