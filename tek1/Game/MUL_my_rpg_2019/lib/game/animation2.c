/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** animation2
*/

#include "game.h"
#include "json.h"
#include <stdlib.h>

void animation_destroy(animation_t *anim)
{
    ll_destroy_content(anim->frames);
    ll_destroy(anim->frames);
    free(anim);
}

void append_frame(animation_t *anim, int time, sfIntRect rect)
{
    animation_frame_t *frame = malloc(sizeof(animation_frame_t));

    frame->rect = rect;
    frame->time = time;
    anim->frames = ll_append(anim->frames, frame);
}

animation_t *anim_from_spritesheet(sfSprite *s, sfIntRect size,
    vector2i_t frame_count_and_len, vector2i_t starting_frame)
{
    animation_t *anim = create_animation(s);
    vector2i_t pos = starting_frame;
    int fcount = frame_count_and_len.x;
    int flength = frame_count_and_len.y;

    flength *= 1000;
    for (int i = 1; i <= fcount; i++) {
        append_frame(anim, i * flength, create_int_rect(pos.x * size.width,
            pos.y * size.height, size.width, size.height));
        pos.x++;
        if (pos.x >= size.left) {
            pos.y++;
            pos.x = 0;
        }
        if (pos.y >= size.top)
            break;
    }
    return anim;
}

animation_t *import_animation(char *file)
{
    char *file_path = my_strconcat("./assets/animations/", file);
    json_object_t *obj = my_free_assign(file_path, read_json(file_path));
    dictionary_t *settings = dict_get((dictionary_t *)(obj->data), "settings");
    animation_t *anim = create_animation(NULL);
    json_object_t *frames = dict_get((dictionary_t *)(obj->data), "frames");
    int time;
    linked_list_t *coords;
    sfIntRect rect;

    anim->loop = *(int *) dict_get(settings, "loop");
    anim->frames = 0;
    for (json_object_t *i = frames; i; i = i->next) {
        time = *(int *) dict_get((dictionary_t *)i->data, "time");
        coords = dict_get((dictionary_t *)i->data, "rect");
        rect = int_rect_from_ll(coords);
        append_frame(anim, time, rect);
    }
    json_destroy(obj);
    return anim;
}