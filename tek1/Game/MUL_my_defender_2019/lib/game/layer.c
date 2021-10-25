/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** layer
*/

#include "game.h"
#include <stdlib.h>

linked_list_t *fill_tiles(linked_list_t *map, tileset_t *t)
{
    linked_list_t *tiles = 0;
    linked_list_t *row;

    for (linked_list_t *y = map; y; y = y->next) {
        row = 0;
        for (linked_list_t *x = y->data; x; x = x->next)
            row = ll_append(row, ll_get(t->tiles, *(int *) x->data));
        tiles = ll_append(tiles, row);
    }
    return tiles;
}

layer_t *parse_map(linked_list_t *map, tileset_t *t)
{
    layer_t *layer = malloc(sizeof(layer_t));
    int height = ll_len(map);
    int width = height > 0 ? ll_len(map->data) : 0;

    layer->scroll_speed = v2f(1, 1);
    layer->sprite = sfSprite_create();
    layer->texture = sfTexture_create(width * t->tile_size.x,
        height * t->tile_size.y);
    sfSprite_setTexture(layer->sprite, layer->texture, sfTrue);
    layer->tiles = ll_append(0, 0);
    layer->tiles = fill_tiles(map, t);
    return layer;
}

void render_layer(sfRenderWindow *win, layer_t *layer)
{
    linked_list_t *i = layer->tiles;
    linked_list_t *j = i->data;
    tile_t *tile;
    vector2i_t pos = {0, 0};

    while (i) {
        tile = j ? j->data : 0;
        if (tile != 0)
            sfTexture_updateFromImage(layer->texture, tile->image, (pos.x - 1) *
            tile->tileset->tile_size.x, pos.y * tile->tileset->tile_size.y);
        j = j ? j->next : 0;
        pos.x++;
        if (!j) {
            i = i->next;
            pos.y++;
            j = i ? i->data : 0;
            pos.x = 0;
        }
    }
    sfRenderWindow_drawSprite(win, layer->sprite, NULL);
}

void render_layers(sfRenderWindow *win, linked_list_t *layers)
{
    linked_list_t *i = layers;

    while (i) {
        render_layer(win, i->data);
        i = i->next;
    }
}

linked_list_t *check_layer_collision(entity_t *e, layer_t *layer)
{
    linked_list_t *collisions = 0;
    tile_t *tile = ((linked_list_t *) layer->tiles->data)->data;
    sfVector2f entity_pos = sfSprite_getPosition(e->sprite);
    sfVector2f pos = sfSprite_getPosition(layer->sprite);
    tileset_t *tileset = tile->tileset;

    pos.x -= tileset->tile_size.x;
    for (linked_list_t *i = layer->tiles; i; i = i->next) {
        for (linked_list_t *j = i->data; j; j = j->next) {
            collisions = ll_concat(collisions, check_collision(entity_pos,
                e->hitbox, pos, ((tile_t *)j->data)->hitbox));
            pos.x += tileset->tile_size.x;
        }
        pos.x = sfSprite_getPosition(layer->sprite).x - tileset->tile_size.x;
        pos.y += tileset->tile_size.y;
    }
    return collisions;
}