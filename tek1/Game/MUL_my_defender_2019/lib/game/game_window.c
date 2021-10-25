/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** game_window
*/

#include "game.h"
#include <stdlib.h>

dictionary_t *init_game_data(window_settings_t s, sfView *view)
{
    dictionary_t *game_data = 0;
    char **new_argv = malloc(sizeof(char *) * s.argc);
    sfVector2f *center = malloc(sizeof(sfVector2f));

    center->x = s.width * s.zoom / 2;
    center->y = s.height * s.zoom / 2;
    sfView_zoom(view, s.zoom);
    sfView_setCenter(view, *center);
    for (int i = 0; i < s.argc; i++) new_argv[i] = my_strdup(s.argv[i]);
    game_data = dict_add(game_data, "width", pint(s.width));
    game_data = dict_add(game_data, "height", pint(s.height));
    game_data = dict_add(game_data, "zoom", pint(s.zoom));
    game_data = dict_add(game_data, "argc", pint(s.argc));
    game_data = dict_add(game_data, "argv", new_argv);
    game_data = dict_add(game_data, "layers", 0);
    game_data = dict_add(game_data, "tilesets", 0);
    game_data = dict_add(game_data, "view", view);
    game_data = dict_add(game_data, "center", center);
    return dict_add(game_data, "map", my_strdup(""));
}

void redraw_window(sfRenderWindow *window, dictionary_t *entities,
    sfClock *clock, dictionary_t *game_data)
{
    sfRenderWindow_clear(window, sfBlack);
    render_layers(window, dict_get(game_data, "layers"));
    display_entities(entities, window,
        sfTime_asMicroseconds(sfClock_getElapsedTime(clock)));
}

void handle_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
}

void destroy_all(dictionary_t *entities, dictionary_t *game_data,
    sfRenderWindow *window)
{
    destroy_entities(entities, 1);
    dict_destroy_content(game_data);
    dict_destroy(game_data);
    sfRenderWindow_destroy(window);
}

int create_game_window(window_settings_t s, dictionary_t *entities,
    int (*game)(sfRenderWindow *, sfClock *, dictionary_t **,
    dictionary_t **), sfClock *clock)
{
    sfRenderWindow* window;
    sfEvent event;
    sfView *view = sfView_createFromRect(float_rect(0, 0, s.width, s.height));
    dictionary_t *game_data = init_game_data(s, view);
    int return_value = 0;

    window = create_window(s.title, s.width, s.height);
    if (!window) return 84;
    sfRenderWindow_setFramerateLimit(window, s.framerate);
    while (sfRenderWindow_isOpen(window)) {
        handle_events(window, event);
        sfRenderWindow_setView(window, view);
        apply_parallax(dict_get(game_data, "layers"), view,
            dict_get(game_data, "center"));
        redraw_window(window, entities, clock, game_data);
        if ((return_value = game(window, clock, &entities, &game_data))) break;
        sfRenderWindow_display(window);
    }
    destroy_all(entities, game_data, window);
    return return_value - 1;
}