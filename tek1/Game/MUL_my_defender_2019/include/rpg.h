/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include "game.h"
#include <stdlib.h>

typedef struct combat_stats {
    int health;
    int armor;
    int attack;
    int defense;
} combat_stats_t;

typedef struct reward {
    char *type;
    char *item;
    int value;
} reward_t;

typedef struct objective {
    char *instruction;
    char *type;
    char *target;
    int progress;
    int nb_required;
    linked_list_t *rewards;
} objective_t;

typedef struct quest {
    char *file;
    char *name;
    dictionary_t *objectives;
    char *objective;
    char *given_by;
    char *redeem_to;
    linked_list_t *rewards;
} quest_t;

typedef struct gameplay_data {
    int player_level;
    int xp_current;
    int xp_needed;
    combat_stats_t *stats;
    quest_t *current_quest;
} gameplay_data_t;

typedef struct dialogue_choice {
    char *text;
    char *go_to;
} dialogue_choice_t;

typedef struct dialogue_line {
    char *name;
    char *text;
    linked_list_t *choices;
} dialogue_line_t;

typedef struct dialogue_part {
    char *name;
    linked_list_t *lines;
    linked_list_t *quests;
    linked_list_t *rewards;
} dialogue_part_t;

typedef struct dialogue_progress {
    dialogue_part_t *part;
    int line;
} dialogue_progress_t;

typedef struct dialogue_condition {
    char *type;
    char *quest;
    char *condition;
    double value;
} dialogue_condition_t;

typedef struct dialogue {
    char *npc;
    linked_list_t *conditions;
    char *default_part;
    dictionary_t *parts;
    dialogue_progress_t *progress;
} dialogue_t;

typedef struct player_move {
    dialogue_t **dial;
    dictionary_t **gamedata;
    dictionary_t **entities;
    entity_t *player;
    char **current_animation;
    char **frame_anim;
    int *moving;
    int time;
} player_move_t;

typedef struct fight_arguments {
    int delta_time;
    combat_stats_t *player_stats;
    combat_stats_t *enemy_stats;
} fight_arguments_t;

dialogue_t *import_dialogue(char *filename);
dictionary_t *entity_load_dialogues(char *name, json_object_t *obj);
void render_dialogue(sfRenderWindow *win, dialogue_t *dial,
dictionary_t **gamedata, int selected_choice);
int dial_progress(dialogue_t *dial, int selected_choice, quest_t **quest);
void player_movement(dictionary_t **gamedata, dictionary_t **entities,
    dialogue_t **dial, int delta_time);
void dialogue_input(dialogue_t **dial, int *selected_choice, quest_t **quest);
reward_t *import_reward(json_object_t *obj);
void init_fight(dialogue_t **dial, int spell);
quest_t *import_quest(char *filename);
sfFont *load_font(char *name, char *file, dictionary_t **gamedata);
sfText *create_text(sfFont *font, char *name, sfVector2f pos,
    dictionary_t **gamedata);
sfText *load_text(sfFont *font, char *name, sfVector2f pos,
    dictionary_t **gamedata);
void render_quest(sfRenderWindow *win, quest_t *quest, dictionary_t **gamedata);
quest_t *quest_progress(quest_t *quest, char *progress_type, char *target,
    int amount);
int check_main_menu_buttons(const sfWindow *window, dictionary_t **entities,
dictionary_t **gamedata);
int real_damage(int damage, int defense);
int p_spell(int n, combat_stats_t *enemy_stats, combat_stats_t *player_stats);
void enemy_turn(combat_stats_t *player_stats);
void player_turn(combat_stats_t *player_stats, combat_stats_t *enemy_stats,
                dialogue_t **dial, int spell);
void check_loading_zones(dictionary_t **entities, dictionary_t **gamedata);
dialogue_t *dialogue_start(entity_t *entity, quest_t *quest);
int display_pause_menu(const sfWindow* window, dictionary_t **entities,
    dictionary_t **gamedata);
void fight_frame(dialogue_t **dial, dictionary_t **gamedata,
    dictionary_t **entities, fight_arguments_t args);
void hurt(combat_stats_t *who, int damage);
int p_spell(int n, combat_stats_t *enemy_stats, combat_stats_t *player_stats);
void render_pve(sfRenderWindow *win, dictionary_t **gamedata,
                combat_stats_t *player_stats, combat_stats_t *enemy_stats);
void start_fight(dialogue_t **dial, dictionary_t **gamedata,
    dictionary_t **entities);
int end_fight(combat_stats_t player_stats, dialogue_t **dial,
    dictionary_t **gamedata, dictionary_t **entities);

#endif /* !RPG_H_ */