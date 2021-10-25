/*
** EPITECH PROJECT, 2019
** my_putpixel
** File description:
** my_putpixel
*/

#include "game.h"

void my_putpixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor
    color)
{
    fb->pixels[y * fb->width + x] = color;
}