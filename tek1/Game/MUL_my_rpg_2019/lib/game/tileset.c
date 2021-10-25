/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** tile
*/

#include "game.h"
#include "json.h"
#include <stdlib.h>

sfImage *get_tile_image(sfImage *tileset_i, sfIntRect coords)
{
    sfImage *image = sfImage_createFromColor(coords.width, coords.height,
        sfColor_fromRGBA(255, 255, 255, 0));

    if (coords.left >= 0 && coords.top >= 0)
        sfImage_copyImage(image, tileset_i, 0, 0, coords, sfFalse);
    return image;
}

linked_list_t *populate_tileset(tileset_t *tileset, int width, int height,
    vector2i_t tile_size)
{
    linked_list_t *tiles = 0;
    tile_t *tile;
    vector2i_t pos = {-1, -1};

    while (pos.y < height) {
        tile = malloc(sizeof(tile_t));
        tile->image = get_tile_image(tileset->image,
            create_int_rect(pos.x * tile_size.x, pos.y * tile_size.y,
            tile_size.x, tile_size.y));
        tile->tileset = tileset;
        tile->hitbox = 0;
        tiles = ll_append(tiles, tile);
        pos.x++;
        if (pos.x >= width || pos.y < 0) {
            pos.x = 0;
            pos.y++;
        }
    }
    return tiles;
}

tileset_t *create_tileset(char *file, int width, int height)
{
    tileset_t *tileset = malloc(sizeof(tileset_t));
    sfVector2u size;
    vector2i_t tile_size;

    tileset->image = sfImage_createFromFile(file);
    tileset->size = v2i(width, height);
    size = sfImage_getSize(tileset->image);
    tile_size.x = size.x / width;
    tile_size.y = size.y / height;
    tileset->tile_size = tile_size;
    tileset->tiles = populate_tileset(tileset, width, height, tile_size);
    return tileset;
}

void create_tile_hitbox(tileset_t *tileset, int tile_nb,
    linked_list_t *hitboxes)
{
    tile_t *tile = ll_get(tileset->tiles, tile_nb);
    hitbox_t *hitbox;
    sfFloatRect box;

    for (linked_list_t *i = hitboxes; i; i = i->next) {
        hitbox = malloc(sizeof(hitbox_t));
        box = float_rect_from_ll(dict_get(i->data, "rect"));
        box.left *= tileset->tile_size.x;
        box.width *= tileset->tile_size.x;
        box.top *= tileset->tile_size.y;
        box.height *= tileset->tile_size.y;
        hitbox->entity = 0;
        hitbox->box = box;
        hitbox->type = hitbox_type(dict_get(i->data, "type"));
        tile->hitbox = ll_append(tile->hitbox, hitbox);
    }
}

tileset_t *import_tileset(char *filename)
{
    char *path = my_strconcat("./assets/tilesets/", filename);
    json_object_t *obj = my_free_assign(path, read_json(path));
    vector2i_t size = v2i(*(int *) ll_get(dict_get(obj->data, "size"), 0),
        *(int *) ll_get(dict_get(obj->data, "size"), 1));
    tileset_t *tileset;

    path = my_strconcat("./assets/images/tilesets/",
        dict_get(obj->data, "file"));
    tileset = my_free_assign(path, create_tileset(path, size.x, size.y));
    for (json_object_t *i = dict_get(obj->data, "hitboxes"); i; i = i->next)
        create_tile_hitbox(tileset, *(int *) dict_get(i->data, "tile"),
            dict_get(i->data, "boxes"));
    json_destroy(obj);
    return tileset;
}