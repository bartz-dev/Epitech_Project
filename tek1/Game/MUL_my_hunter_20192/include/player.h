/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** player functions (header file)
*/

# include "hunter.h"

# ifndef PLAYER_H
# define PLAYER_H

typedef struct duck_info {
	int 			speed;
	int 			count;
} duck_info_t;

duck_info_t 		get_duck_infos(param_t *param);
void 				life_indicator(param_t *param);
void 				update_player_info(param_t *param);

# endif