/*
** EPITECH PROJECT, 2019
** libgame
** File description:
** graphics
*/

#ifndef LIBGAME_H_
#define LIBGAME_H_

#include <SFML/Graphics.h>
#include "tools.h"
#include "linked.h"
#include "json.h"

// HITBOX TYPES
#define HITBOX_UNKNOWN 0
#define HITBOX_DAMAGE 1
#define HITBOX_WALL 2
#define HITBOX_TRIGGER 3
#define HITBOX_PLAYER 4

typedef struct framebuffer {
    sfColor *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;
typedef struct animation {
    sfSprite *sprite;
    int playing;
    int loop;
    int starting_time;
    linked_list_t *frames;
} animation_t;
typedef struct animation_frame {
    sfIntRect rect;
    int time;
} animation_frame_t;
typedef struct entity {
    sfSprite *sprite;
    sfTexture *texture;
    dictionary_t *animations;
    linked_list_t *hitbox;
    int show;
    int persistant;
    dictionary_t *extra_data;
} entity_t;
typedef struct window_settings {
    char *title;
    int width;
    int height;
    int framerate;
    float zoom;
    int argc;
    char **argv;
} window_settings_t;
typedef struct tileset {
    sfImage *image;
    vector2i_t tile_size;
    vector2i_t size;
    linked_list_t *tiles;
} tileset_t;
typedef struct hitbox {
    entity_t *entity;
    sfFloatRect box;
    int type;
} hitbox_t;
typedef struct collision {
    hitbox_t *box1;
    hitbox_t *box2;
} collision_t;
typedef struct tile {
    sfImage *image;
    tileset_t *tileset;
    linked_list_t *hitbox;
} tile_t;
typedef struct layer {
    sfSprite *sprite;
    sfTexture *texture;
    vector2f_t scroll_speed;
    linked_list_t *tiles;
} layer_t;

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void framebuffer_destroy(framebuffer_t *fb);
void my_putpixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor
    color);
sfRenderWindow *create_window(char *title, int width, int height);
sfIntRect create_int_rect(int left, int top, int width, int height);
sfSprite *create_sprite_from_file(char *filename, sfTexture **tex,
    sfIntRect *rect);
animation_t *create_animation(sfSprite *sprite);
void start_animation(entity_t *entity, char *anim_name, int time);
void stop_animation(entity_t *entity, char *anim_name);
void animate(animation_t *anim, int time);
void cycle_animations(dictionary_t *animations, int time);
void animation_destroy(animation_t *anim);
void append_frame(animation_t *anim, int time, sfIntRect rect);
animation_t *anim_from_spritesheet(sfSprite *s, sfIntRect size,
    vector2i_t frame_count_and_len, vector2i_t starting_frame);
entity_t *create_entity(sfSprite *sprite, sfTexture *texture,
    dictionary_t *animations);
dictionary_t *destroy_entities(dictionary_t *entities, int destroy_persistant);
void display_entities(dictionary_t *entities, sfRenderWindow *window,
    int time);
sfVector2i sv2i(int x, int y);
sfVector2f sv2f(float x, float y);
sfVector3f sv3f(float x, float y, float z);
int create_game_window(window_settings_t s, dictionary_t *entities,
    int (*game_logic)(sfRenderWindow *, sfClock *, dictionary_t **,
    dictionary_t **), sfClock *clock);
sfImage *get_tile_image(sfImage *tileset_i, sfIntRect coords);
linked_list_t *populate_tileset(tileset_t *tileset, int width, int height,
    vector2i_t tile_size);
tileset_t *create_tileset(char *file, int width, int height);
layer_t *parse_map(linked_list_t *map, tileset_t *t);
void render_layer(sfRenderWindow *win, layer_t *layer);
void render_layers(sfRenderWindow *win, linked_list_t *layers);
sfFloatRect float_rect(float left, float top, float width, float height);
void apply_parallax(linked_list_t *layers, sfView *view, sfVector2f *center);
animation_t *import_animation(char *file);
entity_t *import_entity(char *filename);
dictionary_t *imp_add_anim(dictionary_t *animations, sfSprite *sprite,
    animation_t *a, char *name);
sfFloatRect float_rect_from_ll(linked_list_t *list);
sfIntRect int_rect_from_ll(linked_list_t *list);
int hitbox_type(char *type);
hitbox_t *get_hitbox(int type, sfFloatRect box);
int check_collision_type(linked_list_t *collisions, int type);
linked_list_t *check_collision(sfVector2f pos1, linked_list_t *hitbox1,
    sfVector2f pos2, linked_list_t *hitbox2);
tileset_t *import_tileset(char *filename);
void destroy_tileset(void *tileset);
void destroy_layer(void *layer);
sfVector2f sv2f_from_ll(linked_list_t *list);
void import_map(char *filename, dictionary_t **entities,
    dictionary_t **gamedata);
linked_list_t *load_layers(json_object_t *obj, dictionary_t **tilesets);
dictionary_t *load_entities(dictionary_t *entities, linked_list_t *obj);
void parse_hitbox(entity_t *e, linked_list_t *obj);
linked_list_t *check_entity_coll(entity_t *e1, entity_t *e2);
linked_list_t *check_layer_collision(entity_t *e, layer_t *layer);
linked_list_t *check_all_collisions(entity_t *e,
    char *name, dictionary_t *entities, linked_list_t *layers);
sfFloatRect scale_float_rect(sfFloatRect rect, sfFloatRect scale);
linked_list_t *scale_hitbox(linked_list_t *hitbox, sfVector2f scale);
dictionary_t *sort_entities(dictionary_t *entities);

#endif /* !LIBGAME_H_ */