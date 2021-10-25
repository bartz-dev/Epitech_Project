/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Returns a number contained in a string
*/

int my_getnbr(char const *str)
{
    long int nb = 0;
    int nbr = 0;
    int p = 0;

    while (str[p]) {
        if (nb == 0 && str[p] == '-')
            nbr = nb == 0 ? nbr + 1 : nbr;
        else if (nb != 0 && (str[p] < '0' || str[p] > '9'))
            break;
        else
            nb = (str[p] < '0' || str[p] > '9') ? nb : nb * 10 + str[p] - '0';
        p++;
    }
    nb = nbr % 2 == 1 ? -nb : nb;
    if (nb < -2147483647 || nb > 2147483647)
        return (0);
    return (nb);
}
