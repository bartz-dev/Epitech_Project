/*
** EPITECH PROJECT, 2020
** libgame
** File description:
** destroy
*/

#include "game.h"
#include <stdlib.h>

void destroy_tile(void *tile)
{
    tile_t *t = tile;

    ll_free(t->hitbox, free);
    sfImage_destroy(t->image);
    free(t);
}

void destroy_tileset(void *tileset)
{
    tileset_t *t = tileset;

    sfImage_destroy(t->image);
    ll_free(t->tiles, destroy_tile);
    free(t);
}

void destroy_layer(void *layer)
{
    layer_t *lay = layer;

    sfSprite_destroy(lay->sprite);
    sfTexture_destroy(lay->texture);
    ll_free(lay->tiles, no_free);
}