/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** render.c
*/

#include "rpg.h"

void render_pve(sfRenderWindow *win, dictionary_t **gamedata,
                combat_stats_t *player_stats, combat_stats_t *enemy_stats)
{
    sfFont *font_title = load_font("title_font",
        "./assets/fonts/Ubuntu-C.ttf", gamedata);
    sfFont *font_obj = load_font("textbox_font",
        "./assets/fonts/Ubuntu-R.ttf", gamedata);
    sfText *player_hp = load_text(font_title, "p_hp", sv2f(100, 30), gamedata);
    sfText *enemy_hp = load_text(font_obj, "e_hp", sv2f(696, 30), gamedata);
    char *p_hp = my_strconcat("Vie du joueur: ",
        my_int_to_str(player_stats->health));
    char *e_hp = my_strconcat("Vie de Breton: ",
        my_int_to_str(enemy_stats->health));

    sfText_setString(player_hp, p_hp);
    sfText_setString(enemy_hp, e_hp);
    if (!my_strcmp(dict_get(*gamedata, "map"), "combat.map")) {
        sfRenderWindow_drawText(win, player_hp, NULL);
        sfRenderWindow_drawText(win, enemy_hp, NULL);
    }
}