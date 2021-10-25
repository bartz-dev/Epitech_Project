/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** find error for bsq
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void test_argv(int argc)
{
    if (argc != 2) {
        write(2, "./bsq [map]\n", 13);
        exit (84);
    }
}

void find_file(int fd)
{
    if (fd == -1) {
        write(2, "Fichier introuvable\n", 21);
        write(2, "./bsq [map]\n", 13);
        exit (84);
    }
}

void test_file(char *tab)
{
    if (tab == NULL) {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        exit (84);
    }
}

void test_char(char letter)
{
    if (letter != '.' && letter != 'o' && letter != '\n' && letter != '\0') {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        exit (84);
    }
}

void empty_file(char letter)
{
    if (letter == '\0') {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        exit (84);
    }
}
