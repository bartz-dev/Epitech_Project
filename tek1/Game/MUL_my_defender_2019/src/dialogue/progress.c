/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** progress
*/

#include "rpg.h"

void end_part_rewards(dialogue_t *dial, dialogue_part_t *part, quest_t **quest)
{
    if (part->quests) {
        *quest = import_quest(part->quests->data);
        (*quest)->given_by = dial->npc;
        (*quest)->file = part->quests->data;
    }
}

void handle_dial_choice(dialogue_t *dial, quest_t **quest,
    int *line_nb, int selected_choice)
{
    dialogue_part_t *part = dial->progress->part;
    dialogue_line_t *current_line = ll_get(part->lines, *line_nb);
    dialogue_choice_t *choice = ll_get(current_line->choices,
        selected_choice - 1);

    if (my_strcmp(choice->go_to, "")) {
        end_part_rewards(dial, part, quest);
        dial->progress->part = dict_get(dial->parts, choice->go_to);
        *line_nb = 0;
    } else (*line_nb)++;
}

int dial_progress(dialogue_t *dial, int selected_choice, quest_t **quest)
{
    dialogue_progress_t *prog = dial->progress;
    dialogue_part_t *prog_part = prog->part;
    dialogue_line_t *line = ll_get(prog_part->lines, prog->line);

    if (line->choices && selected_choice) {
        handle_dial_choice(dial, quest, &(prog->line), selected_choice);
    } else if (!line->choices) prog->line++;
    if (prog->line >= ll_len(prog_part->lines)) {
        end_part_rewards(dial, prog_part, quest);
        *quest = quest_progress(*quest, "QUEST_TALK", dial->npc, 1);
        prog->line = 0;
        prog->part = dict_get(dial->parts, dial->default_part);
        return 0;
    }
    return 1;
}

void dialogue_input(dialogue_t **dial, int *selected_choice, quest_t **quest)
{
    static int interract_pressed = 0;
    static int q_pressed = 1;
    static int d_pressed = 1;
    dialogue_line_t *line = *dial ? ll_get((*dial)->progress->part->lines,
        (*dial)->progress->line) : 0;
    int choices = line && line->choices ? ll_len(line->choices) : 0;

    if (sfKeyboard_isKeyPressed(sfKeyQ) && *dial && !q_pressed) {
        *selected_choice -= *selected_choice > 1 ? 1 : 0;
        q_pressed = 1;
    } else if (!sfKeyboard_isKeyPressed(sfKeyQ)) q_pressed = 0;
    if (sfKeyboard_isKeyPressed(sfKeyD) && *dial && !d_pressed) {
        *selected_choice += *selected_choice < min(choices, 4) ? 1 : 0;
        d_pressed = 1;
    } else if (!sfKeyboard_isKeyPressed(sfKeyD)) d_pressed = 0;
    if (sfKeyboard_isKeyPressed(sfKeyE) && *dial && !interract_pressed) {
        if (!dial_progress(*dial, *selected_choice, quest)) *dial = 0;
        interract_pressed = 1;
    } else if (!sfKeyboard_isKeyPressed(sfKeyE)) interract_pressed = 0;
}