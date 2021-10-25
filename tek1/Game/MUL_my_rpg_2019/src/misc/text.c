/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** text
*/

#include "rpg.h"

sfText *create_text(sfFont *font, char *name, sfVector2f pos,
    dictionary_t **gamedata)
{
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, pos);
    *gamedata = dict_add(*gamedata, name, text);
    return text;
}

sfText *load_text(sfFont *font, char *name, sfVector2f pos,
    dictionary_t **gamedata)
{
    sfText *text = dict_get(*gamedata, name);

    if (text) return text;
    else return create_text(font, name, pos, gamedata);
}

sfFont *load_font(char *name, char *file, dictionary_t **gamedata)
{
    sfFont *font = dict_get(*gamedata, name);

    if (!font) {
        font = sfFont_createFromFile(file);
        *gamedata = dict_add(*gamedata, name, font);
    }
    return font;
}