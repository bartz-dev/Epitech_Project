/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** entity
*/

#include "game.h"
#include "tools.h"
#include "json.h"
#include <stdlib.h>

linked_list_t *check_entity_coll(entity_t *e1, entity_t *e2)
{
    return check_collision(sfSprite_getPosition(e1->sprite), e1->hitbox,
        sfSprite_getPosition(e2->sprite), e2->hitbox);
}

entity_t *import_entity(char *filename)
{
    char *file_path = my_strconcat("./assets/entities/", filename);
    json_object_t *obj = my_free_assign(file_path, read_json(file_path));
    sfTexture *texture = 0;
    sfSprite *sprite;
    dictionary_t *anim = 0;
    entity_t *e;

    file_path = my_strconcat("./assets/images/sprites/",
        dict_get((dictionary_t *)obj->data, "sprite"));
    sprite = create_sprite_from_file(file_path, &texture, NULL);
    for (dictionary_t *i = dict_get((dictionary_t *)obj->data, "animations");
        i; i = i->next)
        anim = imp_add_anim(anim, sprite, import_animation(i->data), i->index);
    e = create_entity(sprite, texture, anim);
    start_animation(e,
        dict_get((dictionary_t *)obj->data, "default_animation"), 0);
    parse_hitbox(e, dict_get(obj->data, "hitboxes"));
    json_destroy(obj);
    free(file_path);
    return e;
}

entity_t *create_entity(sfSprite *sprite, sfTexture *texture,
    dictionary_t *animations)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sprite;
    entity->animations = animations;
    entity->extra_data = 0;
    entity->texture = texture;
    entity->show = 1;
    entity->hitbox = 0;
    entity->persistant = 0;
    return entity;
}

dictionary_t *destroy_entities(dictionary_t *entities, int destroy_persistant)
{
    entity_t *e;
    dictionary_t *next;

    if (!entities) return 0;
    e = entities->data;
    if (entities->next)
        entities->next = destroy_entities(entities->next, destroy_persistant);
    if (e->persistant && !destroy_persistant) return entities;
    next = entities->next;
    dict_destroy_content(e->animations);
    dict_destroy(e->animations);
    sfTexture_destroy(e->texture);
    sfSprite_destroy(e->sprite);
    dict_destroy_content(e->extra_data);
    dict_destroy(e->extra_data);
    free(e);
    free(entities);
    return next;
}

void display_entities(dictionary_t *entities, sfRenderWindow *window,
    int time)
{
    dictionary_t *iterator = entities;
    entity_t *e;

    while (iterator) {
        e = iterator->data;
        if (e->show) {
            cycle_animations(e->animations, time);
            sfRenderWindow_drawSprite(window, e->sprite, NULL);
        }
        iterator = iterator->next;
    }
}