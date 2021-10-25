/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** movement
*/

#include "rpg.h"
#include <stdlib.h>

void reset_to_idle(entity_t *player, char **current_animation, int moving,
    int time)
{
    if (!moving && !my_str_startswith(*current_animation, "idle")) {
        *current_animation = my_str_endswith(*current_animation, "down") ?
            "idle_down" : (my_str_endswith(*current_animation, "up") ?
            "idle_up" : (my_str_endswith(*current_animation, "left") ?
            "idle_left" : "idle_right"));
        for (dictionary_t *i = player->animations; i; i = i->next)
            stop_animation(player, i->index);
        start_animation(player, *current_animation, time);
    }
}

void player_change_anim(player_move_t pm, char *anim)
{
    if (!my_strcmp(*pm.current_animation, anim))
        *pm.frame_anim = anim;
    else if (!my_str_startswith(*pm.frame_anim, "walk")) {
        *pm.current_animation = anim;
        *pm.frame_anim = anim;
        for (dictionary_t *i = pm.player->animations; i; i = i->next)
            stop_animation(pm.player, i->index);
        start_animation(pm.player, anim, pm.time);
    }
}

void player_move(vector2f_t pos, dictionary_t **gamedata,
    dictionary_t **entities, dialogue_t **current_dial)
{
    entity_t *player;
    linked_list_t *collisions;
    linked_list_t *layers = dict_get(*gamedata, "layers");
    collision_t *c;

    player = dict_get(*entities, "player");
    sfSprite_move(player->sprite, sv2f(pos.x, pos.y));
    collisions = check_all_collisions(player, "player", *entities, layers);
    if (check_collision_type(collisions, HITBOX_WALL)) {
        sfSprite_move(player->sprite, sv2f(-pos.x, -pos.y));
        c = ll_get(collisions, 0);
        *current_dial = c->box2->entity ?
            dialogue_start(c->box2->entity, dict_get(*gamedata, "quest")) : 0;
    }
    ll_free(collisions, free);
}

void player_move_check(int key, char *animation, vector2f_t v, player_move_t pm)
{
    if (sfKeyboard_isKeyPressed(key) && !*pm.dial) {
        *pm.moving = 1;
        player_move(v, pm.gamedata, pm.entities, pm.dial);
        player_change_anim(pm, animation);
    }
}

void player_movement(dictionary_t **gamedata, dictionary_t **entities,
    dialogue_t **dial, int delta)
{
    static int time = 0;
    static char *c_a = "idle_down";
    char *f_a = "idle_down";
    int moving = 0;
    vector2f_t speed = {0.0002, 0.0002};
    entity_t *pl = dict_get(*entities, "player");
    player_move_t pm = {dial, gamedata, entities, pl, &c_a, &f_a, &moving, 0};

    if (!pl) return;
    time += delta;
    pm.time = time;
    if (my_strcmp(dict_get(*gamedata, "map"), "main_menu.map") != 0 &&
        my_strcmp(dict_get(*gamedata, "map"), "pause_menu.map") != 0 &&
        my_strcmp(dict_get(*gamedata, "map"), "player_fight.map") != 0) {
        player_move_check(sfKeyS, "walk_down", v2f(0, delta * speed.y), pm);
        player_move_check(sfKeyZ, "walk_up", v2f(0, -delta * speed.y), pm);
        player_move_check(sfKeyQ, "walk_left", v2f(-delta * speed.x, 0), pm);
        player_move_check(sfKeyD, "walk_right", v2f(delta * speed.x, 0), pm);
        reset_to_idle(pl, &c_a, moving, time);
    }
}