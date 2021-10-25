/*
** EPITECH PROJECT, 2020
** libgame
** File description:
** map
*/

#include "game.h"
#include "json.h"
#include "rpg.h"
#include <stdlib.h>

linked_list_t *load_layers(json_object_t *obj, dictionary_t **tilesets)
{
    linked_list_t *layers = 0;
    tileset_t *tileset;
    layer_t *layer;
    linked_list_t *scroll_speed;

    for (json_object_t *i = obj; i; i = i->next) {
        if (!dict_get(*tilesets, dict_get(i->data, "tileset"))) {
            tileset = import_tileset(dict_get(i->data, "tileset"));
            *tilesets = dict_add(*tilesets, dict_get(i->data, "tileset"),
                tileset);
        } else
            tileset = dict_get(*tilesets, dict_get(i->data, "tileset"));
        layer = parse_map(dict_get(i->data, "terrain"), tileset);
        scroll_speed = dict_get(i->data, "scroll_speed");
        layer->scroll_speed = v2f(*(float *) ll_get(scroll_speed, 0),
            *(float *) ll_get(scroll_speed, 1));
        layers = ll_append(layers, layer);
    }
    return layers;
}

dictionary_t *entity_extra_data(dictionary_t *extra_data, dictionary_t *infos)
{
    json_object_t *data = dict_get(infos, "extra_data");
    void *content;

    extra_data = dict_add(extra_data, "dialogues",
            entity_load_dialogues(dict_get(infos, "name"),
            dict_get(infos, "dialogues")));
    for (json_object_t *i = data; i; i = i->next) {
        if (i->type == JSON_STRING) content = my_strdup(i->data);
        else if (i->type == JSON_INT || i->type == JSON_DOUBLE)
            content = i->type == JSON_INT ? pint(*(int *) i->data) :
                (void *) pdouble(*(double *) i->data);
        else {
            my_printf("Error when importing entity data\n");
            continue;
        }
        extra_data = dict_add(extra_data, my_strdup(i->index), content);
    }
    return extra_data;
}

dictionary_t *load_entities(dictionary_t *entities, linked_list_t *obj)
{
    dictionary_t *entity_informations;
    entity_t *entity;

    for (linked_list_t *i = obj; i; i = i->next) {
        entity_informations = i->data;
        if (*(int *) dict_get(entity_informations, "persistant") &&
            dict_get(entities, dict_get(entity_informations, "name")))
            continue;
        entity = import_entity(dict_get(entity_informations, "file"));
        sfSprite_setPosition(entity->sprite,
            sv2f_from_ll(dict_get(entity_informations, "pos")));
        entity->persistant =
            *(int *) dict_get(entity_informations, "persistant");
        entity->extra_data = entity_extra_data(entity->extra_data,
            entity_informations);
        entities = dict_add(entities, dict_get(entity_informations, "name"),
            entity);
    }
    return entities;
}

void import_map(char *filename, dictionary_t **entities,
    dictionary_t **gamedata)
{
    linked_list_t *layers = 0;
    dictionary_t *tilesets = 0;
    char *path = my_strconcat("./assets/maps/", filename);
    json_object_t *obj = my_free_assign(path, read_json(path));

    free(dict_get(*gamedata, "map"));
    dict_set(*gamedata, "map", my_strdup(filename));
    *entities = destroy_entities(*entities, 0);
    *entities = load_entities(*entities, dict_get(obj->data, "entities"));
    ll_free(dict_get(*gamedata, "layers"), destroy_layer);
    dict_free(dict_get(*gamedata, "tilesets"), 1, destroy_tileset);
    layers = load_layers(dict_get(obj->data, "layers"), &tilesets);
    dict_set(*gamedata, "layers", layers);
    dict_set(*gamedata, "tilesets", tilesets);
}