/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding
*/

#include "lemin.h"

void create_ants(lemin_data_t *data)
{
    ant_t *ant;

    for (int i = 1; i <= data->ants_nb; i++) {
        ant = malloc(sizeof(ant_t));
        ant->nb = i;
        ant->current_room = data->start_room;
        ant->previous_room = 0;
        data->ants = ll_append(data->ants, ant);
    }
}

char *tunnel_get_end(tunnel_t *tunnel, char *current_room)
{
    room_t *room;

    if (my_strcmp(tunnel->room1->name, current_room) &&
        my_strcmp(tunnel->room2->name, current_room))
        return 0;
    room = !my_strcmp(tunnel->room1->name, current_room) ? tunnel->room2 :
        tunnel->room1;
    return room->name;
}

int is_ant_in_room(linked_list_t *ants, char *room)
{
    ant_t *ant;

    for (linked_list_t *i = ants; i; i = i->next) {
        ant = i->data;
        if (!my_strcmp(ant->current_room, room))
            return 1;
    }
    return 0;
}

path_t get_shortest_path(char *current_room, char *previous_room,
    lemin_data_t *data)
{
    char *room_name;
    path_t path;
    path_t shortest_path = {0, -1};

    for (linked_list_t *i = data->tunnels; i; i = i->next) {
        room_name = tunnel_get_end(i->data, current_room);
        if (!room_name || (previous_room &&
            !my_strcmp(room_name, previous_room)) || is_ant_in_room(data->ants,
            room_name)) continue;
        if (!my_strcmp(data->end_room, room_name)) {
            shortest_path.room = room_name;
            shortest_path.steps = 0;
            break;
        }
        path = get_shortest_path(room_name, current_room, data);
        if (shortest_path.steps == -1 || path.steps < shortest_path.steps) {
            shortest_path.steps = path.steps;
            shortest_path.room = room_name;
        }
    }
    shortest_path.steps += 1;
    return shortest_path;
}

int next_room(int iter_nb, ant_t *ant, lemin_data_t *data)
{
    path_t path = get_shortest_path(ant->current_room, ant->previous_room,
        data);

    if (!path.room && !my_strcmp(ant->current_room, data->start_room) &&
        ant->nb == 1) {
        my_printf("ERROR: no path from start to end\n");
        return 0;
    } else if (!path.room)
        return -1;
    ant->previous_room = ant->current_room;
    ant->current_room = path.room;
    my_printf("%sP%d-%s", iter_nb == 0 ? "" : " ", ant->nb, ant->current_room);
    return 1;
}