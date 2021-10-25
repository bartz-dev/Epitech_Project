/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** utils functions (header file)
*/

# include "hunter.h"

# ifndef UTILS_H
# define UTILS_H

void 			param_textures(assets_t *ass);
assets_t 		*configure_assets(param_t *param);
void 			initiate_assets(param_t *param);
void 			destroy_assets(param_t *param);

void 			configure_animations(param_t *param);
void 			destroy_animations(param_t *param);

assets_t 		*initiate_assets_struct(void);
playerStat_t 	*initiate_playerStats(void);
param_t 		*initiate_params(void);
sfIntRect 		*configure_rect(int l, int t, int w, int h);
void 			destroy_content(param_t *param);

# endif