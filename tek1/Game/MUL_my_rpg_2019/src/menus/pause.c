/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** principal.c
*/

#include "rpg.h"

int pause_exit_button(sfVector2u size, sfVector2i mouse)
{
    if (mouse.y > 0.475 * size.y && mouse.y < 0.671 * size.y &&
        mouse.x > 0.38 * size.x) {
        if (mouse.x < 0.64 * size.x && sfMouse_isButtonPressed(sfMouseLeft))
            return 1;
    }
    return 0;
}

int back_to_main_menu(sfVector2u size, sfVector2i mouse,
                        dictionary_t **entities, dictionary_t **gamedata)
{
    if (mouse.y > 0.77 * size.y && mouse.y < 0.965 * size.y &&
        mouse.x > 0.38 * size.x) {
        if (mouse.x < 0.64 * size.x && sfMouse_isButtonPressed(sfMouseLeft)) {
            *entities = destroy_entities(*entities, 1);
            import_map("main_menu.map", entities, gamedata);
        }
    }
    return 0;
}

int resume_game(const sfWindow *window, dictionary_t **entities,
    dictionary_t **gamedata, char *map)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    sfVector2u size = sfWindow_getSize(window);
    entity_t *player = dict_get(*entities, "player");

    if (mouse.y > 0.182 * size.y && mouse.y < 0.379 * size.y &&
        mouse.x > 0.38 * size.x) {
        if (mouse.x < 0.64 * size.x && sfMouse_isButtonPressed(sfMouseLeft)) {
            import_map(map, entities, gamedata);
            player->show = 1;
        }
    }
    return 0;
}

int display_pause_menu(const sfWindow *window, dictionary_t **entities,
    dictionary_t **gamedata)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    sfVector2u size = sfWindow_getSize(window);
    static char *map;
    static int is_esc_button_pressed = 0;
    entity_t *player = dict_get(*entities, "player");

    if (my_strcmp(dict_get(*gamedata, "map"), "main_menu.map") != 0 &&
        sfKeyboard_isKeyPressed(sfKeyEscape) && !is_esc_button_pressed) {
        is_esc_button_pressed = 1;
        map = my_strdup(dict_get(*gamedata, "map"));
        import_map("pause_menu.map", entities, gamedata);
        player->show = 0;
    }
    if (my_strcmp(dict_get(*gamedata, "map"), "pause_menu.map") == 0) {
        resume_game(window, entities, gamedata, map);
        back_to_main_menu(size, mouse, entities, gamedata);
        if (pause_exit_button(size, mouse) == 1) return 1;
    }
    else if (is_esc_button_pressed) is_esc_button_pressed = 0;
    return 0;
}