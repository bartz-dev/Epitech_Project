/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** animation functions (header file)
*/

# include "hunter.h"

# ifndef ANIMATION_H
# define ANIMATION_H

typedef struct duck {
	int 			width;
	int 			left;
} duck_t;

void				animate_duck(param_t *param);
void 				restart_animation(param_t *param);

# endif