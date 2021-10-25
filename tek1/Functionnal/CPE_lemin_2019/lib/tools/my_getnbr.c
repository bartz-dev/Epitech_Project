/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Returns a number contained in a string
*/

int my_getnbr(char const *str)
{
    long int nb = 0;
    int minus_nb = 0;
    int i = 0;

    while (str[i]) {
        if (nb == 0 && str[i] == '-')
            minus_nb = nb == 0 ? minus_nb + 1 : minus_nb;
        else if (nb != 0 && (str[i] < '0' || str[i] > '9'))
            break;
        else
            nb = (str[i] < '0' || str[i] > '9') ? nb : nb * 10 + str[i] - '0';
        i++;
    }
    nb = minus_nb % 2 == 1 ? -nb : nb;
    if (nb < -2147483647 || nb > 2147483647)
        return (0);
    return (nb);
}
