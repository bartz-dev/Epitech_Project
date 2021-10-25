/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** render.c
*/

#include "rpg.h"

void create_textbox(sfText **text, sfText **title, sfSprite **box,
    dictionary_t **gamedata)
{
    sfFont *font_title = load_font("title_font",
        "./assets/fonts/Ubuntu-C.ttf", gamedata);
    sfFont *font_text = load_font("textbox_font",
        "./assets/fonts/Ubuntu-R.ttf", gamedata);
    sfTexture *tex;

    create_text(font_text, "cursor", sv2f(110, 610), gamedata);
    *text = create_text(font_text, "textbox_text", sv2f(82, 420), gamedata);
    *title = create_text(font_title, "textbox_title", sv2f(75, 365), gamedata);
    *box = sfSprite_create();
    tex = sfTexture_createFromFile("./assets/images/sprites/textbox.png",
        NULL);
    sfSprite_setTexture(*box, tex, sfTrue);
    sfSprite_setScale(*box, sv2f(0.6, 0.60));
    sfSprite_setPosition(*box, sv2f(60, 350));
    *gamedata = dict_add(*gamedata, "textbox", *box);
    *gamedata = dict_add(*gamedata, "textbox_texture", tex);
}

void create_choices_text(sfFont *font, dictionary_t **gamedata)
{
    create_text(font, "choice1", sv2f(175, 540), gamedata);
    create_text(font, "choice2", sv2f(350, 540), gamedata);
    create_text(font, "choice3", sv2f(525, 540), gamedata);
    create_text(font, "choice4", sv2f(700, 540), gamedata);
}

void render_choices(sfRenderWindow *win, dialogue_line_t *line, sfFont *font,
    dictionary_t **gamedata)
{
    dialogue_choice_t *choice;
    sfText *text = dict_get(*gamedata, "choice1");
    char *name = my_strdup("choice1");

    if (!line->choices) return;
    if (!text) create_choices_text(font, gamedata);
    else {
        sfText_setString(dict_get(*gamedata, "choice1"), "");
        sfText_setString(dict_get(*gamedata, "choice2"), "");
        sfText_setString(dict_get(*gamedata, "choice3"), "");
        sfText_setString(dict_get(*gamedata, "choice4"), "");
    }
    for (linked_list_t *i = line->choices; i; i = i->next) {
        choice = i->data;
        text = dict_get(*gamedata, name);
        sfText_setString(text, choice->text);
        sfRenderWindow_drawText(win, text, NULL);
        name[6] += name[6] < '5' ? 1 : 0;
    }
}

void render_dialogue(sfRenderWindow *win, dialogue_t *dial,
    dictionary_t **G, int c)
{
    sfText *text = dict_get(*G, "textbox_text");
    sfText *title = dict_get(*G, "textbox_title");
    sfSprite *box = dict_get(*G, "textbox");
    dialogue_line_t *line = dial ? ll_get(dial->progress->part->lines,
        dial->progress->line) : 0;

    if (!title || !text) create_textbox(&text, &title, &box, G);
    if (dial) {
        sfText_setString(text, line ? line->text : "");
        sfText_setString(title, line ? line->name : "");
        sfRenderWindow_drawSprite(win, box, NULL);
        sfRenderWindow_drawText(win, text, NULL);
        sfRenderWindow_drawText(win, title, NULL);
        if (line && line->choices) {
            sfText_setString(dict_get(*G, "cursor"), ">");
            sfText_setPosition(dict_get(*G, "cursor"), sv2f(175 * c - 15, 540));
            sfRenderWindow_drawText(win, dict_get(*G, "cursor"), NULL);
        }
        render_choices(win, line, dict_get(*G, "textbox_font"), G);
    }
}