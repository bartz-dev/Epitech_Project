/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "rpg.h"

int fight_logic(sfRenderWindow *win, dialogue_t **dial,
    dictionary_t **gamedata, dictionary_t **entities)
{
    static int time = 0;
    static combat_stats_t player_stats = {200, 100, 50, 20};
    static combat_stats_t enemy_stats = {150, 75, 50, 15};
    int delta_time = *(int *) dict_get(*gamedata, "time") - time;
    fight_arguments_t args = {delta_time, &player_stats, &enemy_stats};

    time = *(int *) dict_get(*gamedata, "time");
    start_fight(dial, gamedata, entities);
    fight_frame(dial, gamedata, entities, args);
    render_pve(win, gamedata, &player_stats, &enemy_stats);
    return 1;
}

int game_logic(sfRenderWindow *win, sfClock *clock, dictionary_t **entities,
    dictionary_t **gdt)
{
    static int tick = 0;
    static int time = 0;
    static int delta_time;
    static dialogue_t *dial = 0;
    static quest_t *quest = 0;
    static int selected_choice = 1;

    *gdt = dict_set(dict_set(*gdt, "quest", quest), "time", pint(time));
    delta_time = sfClock_getElapsedTime(clock).microseconds - time;
    time = sfClock_getElapsedTime(clock).microseconds;
    if (tick == 0) import_map("main_menu.map", entities, gdt);
    dialogue_input(&dial, &selected_choice, &quest);
    player_movement(gdt, entities, &dial, delta_time);
    check_loading_zones(entities, gdt);
    render_quest(win, quest, gdt);
    render_dialogue(win, dial, gdt, selected_choice);
    tick += fight_logic(win, &dial, gdt, entities);
    return check_main_menu_buttons(win, entities, gdt) ||
        display_pause_menu(win, entities, gdt);
}

int main(int argc, char **argv)
{
    window_settings_t s = {"Breton VS Wild", 1080, 720, 60, 0.83, argc, argv};
    dictionary_t *entities = 0;
    sfClock *clock = sfClock_create();

    srand(time());
    if (argc > 1 && !my_strcmp(argv[1], "-h")) {
        my_printf("\nDESCRIPTION\n\t./my_rpg\n\nKEYS\n");
        my_printf("Z\t Go up\nS\t Go down\nD\t Go right\nQ\t Go left\n");
        my_printf("E\t Interact\nEscape   Pause your game\n\n\tHave fun !\n\n");
        return 0;
    }
    return create_game_window(s, entities, game_logic, clock);
}