/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** principal.c
*/

#include "rpg.h"

int exit_button(sfVector2u size, sfVector2i mouse)
{
    if (mouse.y > size.y*0.52 && mouse.y < size.y*0.73 &&
        mouse.x > size.x*0.38) {
        if (mouse.x < size.x*0.64 && sfMouse_isButtonPressed(sfMouseLeft))
            return 1;
    }
    return 0;
}

int launch_game(const sfWindow* window, dictionary_t **entities,
    dictionary_t **gamedata)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    sfVector2u size = sfWindow_getSize(window);

    if (exit_button(size, mouse) == 1)
        return 1;
    if (mouse.y > size.y*0.22 && mouse.y < size.y*0.42 &&
    mouse.x > size.x*0.38) {
        if (mouse.x < size.x*0.64 && sfMouse_isButtonPressed(sfMouseLeft))
            import_map("office.map", entities, gamedata);
    }
    return 0;
}

int check_main_menu_buttons(const sfWindow* window, dictionary_t **entities,
    dictionary_t **gamedata)
{
    if (my_strcmp(dict_get(*gamedata, "map"), "main_menu.map") == 0) {
        if (launch_game(window, entities, gamedata) == 1)
            return 1;
    }
    return 0;
}