/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** combat.c
*/

#include "rpg.h"

int combat_wait(int *wait_time, int delta_time)
{
    *wait_time += delta_time;
    if (*wait_time > 500000) {
        *wait_time = 0;
        return 1;
    }
    return 0;
}

void begin_enemy_turn(dialogue_t **dial, combat_stats_t *player_stats)
{
    int damage = 50 - player_stats->defense;

    *dial = import_dialogue("breton_when_fighting.dial");
    hurt(player_stats, damage);
}

int during_enemy_turn(dialogue_t **dial, combat_stats_t *player_stats,
    combat_stats_t *enemy_stats, int delta_time)
{
    static int wait_time = 0;

    if (!*dial && combat_wait(&wait_time, delta_time))
        return 1;
    return 0;
}

int during_player_turn(dialogue_t **dial, combat_stats_t *player_stats,
    combat_stats_t *enemy_stats, int delta_time)
{
    static int is_btn_pressed = 0;
    static int wait_time = 0;
    char *part = *dial ? (*dial)->progress->part->name : "";

    if (sfKeyboard_isKeyPressed(sfKeyE) && !is_btn_pressed) {
        is_btn_pressed = 1;
        while (sfKeyboard_isKeyPressed(sfKeyE) != sfFalse)
            is_btn_pressed = 1;
        if (!my_strcmp(part, "combat_choice_1"))
            hurt(enemy_stats,
            (p_spell(1, enemy_stats, player_stats) - enemy_stats->defense));
        if (!my_strcmp(part, "combat_choice_2"))
            hurt(enemy_stats,
            (p_spell(2, enemy_stats, player_stats) - enemy_stats->defense));
        if (!my_strcmp(part, "combat_choice_3"))
            hurt(enemy_stats,
            (p_spell(3, enemy_stats, player_stats) - enemy_stats->defense));
    } else if (is_btn_pressed) is_btn_pressed = 0;
    if (!*dial && combat_wait(&wait_time, delta_time))
            return 0;
    return 1;
}

void fight_frame(dialogue_t **dial, dictionary_t **gamedata,
    dictionary_t **entities, fight_arguments_t args)
{
    static int is_player_turn = 1;
    static int previous_player_turn = 0;
    combat_stats_t *player_stats = args.player_stats;
    combat_stats_t *enemy_stats = args.enemy_stats;

    if (!my_strcmp(dict_get(*gamedata, "map"), "combat.map")) {
        if (is_player_turn == 1 && !previous_player_turn)
            *dial = import_dialogue("player_fight.dial");
        else if (!is_player_turn && previous_player_turn)
            begin_enemy_turn(dial, player_stats);
        previous_player_turn = is_player_turn;
        if (is_player_turn == 1)
            is_player_turn = during_player_turn(dial, player_stats,
                enemy_stats, args.delta_time);
        else if (!is_player_turn)
            is_player_turn = during_enemy_turn(dial, player_stats,
                enemy_stats, args.delta_time);
        if (player_stats->health <= 0 || enemy_stats->health <= 0)
            is_player_turn = end_fight(*player_stats, dial, gamedata, entities);
    }
}