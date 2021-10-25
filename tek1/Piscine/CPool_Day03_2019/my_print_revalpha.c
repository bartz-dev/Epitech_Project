/*
** EPITECH PROJECT, 2019
** my_print_revalpha
** File description:
** 
*/

int my_print_revalpha(void)
{
    int i;
    char letters2;

    for (i = 122; i > 96; i--) {
        letters2 = i;
        my_putchar(letters2);
    }
    return(0);
}
