/*
** EPITECH PROJECT, 2019
** create_sprite_from_file
** File description:
** create_sprite_from_file
*/

#include "game.h"

sfSprite *create_sprite_from_file(char *filename, sfTexture **tex,
    sfIntRect *rect)
{
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(filename, rect);
    if (!texture)
        return 0;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    *tex = texture;
    return sprite;
}