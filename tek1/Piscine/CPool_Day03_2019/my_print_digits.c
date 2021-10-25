/*
** EPITECH PROJECT, 2019
** my_print_digits
** File description:
** 
*/

int my_print_digits(void)
{
    int e;
    char digits;

    for (e = 48;e < 58;e++)
    {
        digits = e;
        my_putchar(digits);
    }
}
