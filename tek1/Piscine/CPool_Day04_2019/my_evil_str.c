/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
**
*/

int my_putchar(int c);

int my_strlen(char *str);

char *my_evil_str(char *str)
{
    int i = 0;
    int count = my_strlen(str) - 1;
    int len = my_strlen(str);
    char wr;

    while (i < (len / 2)) {
            wr = str[count];
            str[count] = str[i];
            str[i] = wr;
            count--;
            i++;
    }
        return str;
}
