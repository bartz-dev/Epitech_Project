/*
** EPITECH PROJECT, 2019
** SYN_palindrome_2019
** File description:
** infinadd.c
*/

void infinadd(char *string, int nbr, int base)
{
    int count;
    char alpha[11] = "0123456789";

    for (count = 0; nbr != 0; count++) {
        string[count] = alpha[nbr % base];
        nbr = nbr / base;
    }
    string[count] = '\0';
}