/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** animation
*/

#include <stdlib.h>
#include "game.h"

animation_t *create_animation(sfSprite *sprite)
{
    animation_t *anim = malloc(sizeof(animation_t));

    anim->frames = 0;
    anim->playing = 0;
    anim->sprite = sprite;
    anim->starting_time = 0;
    anim->loop = 1;
    return anim;
}

void start_animation(entity_t *entity, char *anim_name, int time)
{
    animation_frame_t *frame;
    animation_t *anim = dict_get(entity->animations, anim_name);

    if (!anim) return;
    anim->playing = 1;
    anim->starting_time = time;
    frame = anim->frames->data;
    sfSprite_setTextureRect(anim->sprite, frame->rect);
}

void stop_animation(entity_t *entity, char *anim_name)
{
    animation_t *anim = dict_get(entity->animations, anim_name);

    anim->playing = 0;
    anim->starting_time = 0;
}

void animate(animation_t *anim, int time)
{
    linked_list_t *iterator = anim->frames;
    animation_frame_t *frame;

    while (iterator && anim->playing) {
        frame = iterator->data;
        if (frame->time <= time - anim->starting_time && !iterator->next
            && anim->loop) {
            sfSprite_setTextureRect(anim->sprite, frame->rect);
            anim->starting_time = time;
        } else if (frame->time <= time - anim->starting_time) {
            sfSprite_setTextureRect(anim->sprite, frame->rect);
        }
        iterator = iterator->next;
    }
}

void cycle_animations(dictionary_t *animations, int time)
{
    dictionary_t *iterator = animations;

    while (iterator) {
        animation_t *anim = iterator->data;
        animate(anim, time);
        iterator = iterator->next;
    }
}