/*
** EPITECH PROJECT, 2019
** framebuffer_create
** File description:
** framebuffer_create
*/

#include <stdlib.h>
#include "game.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));

    fb->pixels = malloc(sizeof(sfColor) * width * height + 1);
    fb->width = width;
    fb->height = height;
    return fb;
}

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixels);
}