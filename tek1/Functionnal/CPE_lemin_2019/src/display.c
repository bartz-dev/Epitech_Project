/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** display.c
*/

#include "lemin.h"

void display_rooms(lemin_data_t *data)
{
    room_t *room;

    for (dictionary_t *i = data->rooms; i; i = i->next){
        room = i->data;
        if (!my_strcmp(data->start_room, room->name) ||
            !my_strcmp(data->end_room, room->name))
            my_printf("##%s\n", !my_strcmp(data->start_room, room->name) ?
                "start" : "end");
        my_printf("%s %d %d\n", room->name, room->coords.x, room->coords.y);
    }
}

void display_tunnels(lemin_data_t *data)
{
    tunnel_t *tunnel;

    for (linked_list_t *i = data->tunnels; i; i = i->next){
        tunnel = i->data;
        my_printf("%s-%s\n", tunnel->room1->name, tunnel->room2->name);
    }
}

int init_display(lemin_data_t *data)
{

    my_printf("#number_of_ants\n%d\n", data->ants_nb);
    my_printf("#rooms\n");
    display_rooms(data);
    my_printf("#tunnels\n");
    display_tunnels(data);
    my_printf("#moves\n");
    return 0;
}