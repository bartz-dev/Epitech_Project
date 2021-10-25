/*
** EPITECH PROJECT, 2019
** my_create_window
** File description:
** my_create_window
*/

#include "game.h"

sfRenderWindow *create_window(char *title, int width, int height)
{
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, title, sfResize | sfClose,
        NULL);
    return window;
}