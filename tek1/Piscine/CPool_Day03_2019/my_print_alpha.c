/*
** EPITECH PROJECT, 2019
** my_print_alpha
** File description:
** 
*/

int my_print_alpha(void)
{
    char i;
    char letter;

    for (i = 97; i < 123; i++) {
        letter = i;
        my_putchar(letter);
    }
}
