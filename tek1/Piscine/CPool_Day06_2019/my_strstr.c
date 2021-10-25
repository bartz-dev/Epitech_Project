/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** task05
*/

int my_putchar(char c);

int check_common(char *str, char const *to_find)
{
    int i = 0;
    int check = 0;
    int p = 0;

    while (str[i] != '\0') {
        p = 0;
        while (to_find[p] != '\0') {
            if (str[i] == to_find[p]) {
                return (to_find[p]);
                }
            p++;
        }
        i++;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    check_common(str, to_find);
}
