/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** events functions (header file)
*/

# include "hunter.h"

# ifndef EVENTS_H
# define EVENTS_H

void 			mouse_events(param_t *param, sfEvent event);
void 			events_manager(param_t *param, sfEvent event);

void 			mouse_move_event(param_t *param, sfEvent event);
void 			mouse_click_event(param_t *param, sfEvent event);

# endif