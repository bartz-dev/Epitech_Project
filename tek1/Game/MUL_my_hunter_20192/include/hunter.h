/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter functions (header file)
*/

# include <SFML/Graphics.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <limits.h>

# ifndef HUNTER_H
# define HUNTER_H

# define ANNIMA_CNT 1
# define ASSETS_CNT 9

typedef enum state {
	gameWait,
	gamePlay,
	gameEnd
} state_e;

typedef struct assets {
	sfIntRect 				*rec;
	sfTexture 				*texture;
	sfSprite 				*sprite;
} assets_t;

typedef struct animations {
	sfClock 				*clock;
	sfSprite 				*sprite;
	sfInt32 				max_duration;
	sfInt32 				update;
} anim_t;

typedef struct stats {
	int 					round;
	int 					score;
	int 					shoots;
	int 					stade;
	float 					speed_mul;
	bool 					updated;
} playerStat_t;

typedef struct params {
	sfRenderWindow 			*window;
	const sfView 			*fixedView;
	assets_t 				*assets;
	sfText 					*text;
	sfFont 					*default_font;
	playerStat_t 			*player;
	anim_t 					*anim;
	state_e 				state;
} param_t;

void 				check_flags(int ac, char **av);

void 				change_state(param_t *param);
void 				game_wait(param_t *param);
void 				game_play(param_t *param);
void 				game_loader(param_t *param);
void				game_management(param_t *param);

void 				display_score(param_t *param);

# endif