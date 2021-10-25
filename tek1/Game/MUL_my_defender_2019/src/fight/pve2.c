/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** combat.c
*/

#include "rpg.h"

int p_spell(int n, combat_stats_t *enemy_stats, combat_stats_t *player_stats)
{
    if (n == 1)
        return 80;
    if (n == 2) {
        enemy_stats->defense *= 0.9;
        return 50;
    }
    if (n == 3) {
        player_stats->defense += 5;
        return 20;
    }
}

void hurt(combat_stats_t *who, int damage)
{
    if (who->armor > 0.0) {
        who->armor -= damage;
        if (who->armor < 0)
            who->health += who->armor;
    }
    else if (who->health > 0.0)
        who->health -= damage;
}

int end_fight(combat_stats_t player_stats, dialogue_t **dial,
    dictionary_t **gamedata, dictionary_t **entities)
{
    static int first_time = 1;
    quest_t *quest = dict_get(*gamedata, "quest");
    entity_t *player = dict_get(*entities, "player");

    if (player_stats.health <= 0 && !*dial && first_time)
        *dial = import_dialogue("breton_win_fight.dial");
    else if (player_stats.health > 0 && !*dial && first_time)
        *dial = import_dialogue("player_win_fight.dial");
    if (*dial == 0) {
        quest_progress(quest, "QUEST_KILL", "enemy_breton", 1);
        if (player)
            player->show = 1;
        import_map("bde.map", entities, gamedata);
    }
    first_time = 0;
    return 2;
}