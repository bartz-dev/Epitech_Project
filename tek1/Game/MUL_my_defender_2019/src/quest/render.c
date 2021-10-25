/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** render
*/

#include "rpg.h"

void render_quest(sfRenderWindow *win, quest_t *quest, dictionary_t **gamedata)
{
    sfFont *font_title = load_font("title_font",
        "./assets/fonts/Ubuntu-C.ttf", gamedata);
    sfFont *font_obj = load_font("textbox_font",
        "./assets/fonts/Ubuntu-R.ttf", gamedata);
    sfText *title = load_text(font_title, "quest_title", sv2f(10, 10),
        gamedata);
    sfText *obj_txt = load_text(font_obj, "quest_obj", sv2f(10, 50),
        gamedata);
    objective_t *objective;

    if (!quest) return;
    objective = dict_get(quest->objectives, quest->objective);
    sfText_setString(title, quest->name);
    sfText_setString(obj_txt, objective->instruction);
    sfRenderWindow_drawText(win, title, NULL);
    sfRenderWindow_drawText(win, obj_txt, NULL);
}