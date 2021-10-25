/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include "linked.h"
#include "tools.h"

#define R_NORMAL 0
#define R_START 1
#define R_END 2

typedef struct lemin_data {
    int next_room;
    char *start_room;
    char *end_room;
    int ants_nb;
    dictionary_t *rooms;
    linked_list_t *tunnels;
    linked_list_t *ants;
} lemin_data_t;

typedef struct room {
    char *name;
    vector2i_t coords;
} room_t;

typedef struct path {
    char *room;
    int steps;
} path_t;

typedef struct tunnel {
    room_t *room1;
    room_t *room2;
} tunnel_t;

typedef struct ant {
    int nb;
    char *current_room;
    char *previous_room;
} ant_t;

int main(int ac, char **av, char **envp);

int parse_line(lemin_data_t *data);

int init_display(lemin_data_t *data);

void create_ants(lemin_data_t *data);

int next_room(int iter_nb, ant_t *ant, lemin_data_t *data);

#endif /* !LEMIN_H_ */