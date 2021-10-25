/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** parsing
*/

#include "lemin.h"
#include <stdio.h>

int parse_room(lemin_data_t *data, char *line)
{
    room_t *room;
    char **split_str = my_strsplit(line, ' ');
    int array_length = my_arrlen(split_str);

    if (array_length >= 3) {
        if (dict_get(data->rooms, split_str[0])) {
             my_printf("ERROR: room `%s` already exists", split_str[0]);
             return 0;
        }
        room = malloc(sizeof(room_t));
        room->name = my_strdup(split_str[0]);
        room->coords = v2i(my_getnbr(split_str[1]), my_getnbr(split_str[2]));
        data->rooms = dict_add(data->rooms, my_strdup(room->name), room);
        if (data->next_room == R_START) data->start_room = room->name;
        else if (data->next_room == R_END) data->end_room = room->name;
        data->next_room = R_NORMAL;
    }
    free_split(split_str);
    return array_length >= 3;
}

int parse_tunnel(lemin_data_t *data, char *line)
{
    char **split_str = my_strsplit(line, '-');
    int array_length = my_arrlen(split_str);
    room_t *room1;
    room_t *room2;
    tunnel_t *tunnel;

    if (array_length == 2) {
        room1 = dict_get(data->rooms, split_str[0]);
        room2 = dict_get(data->rooms, split_str[1]);
        if (!room1 || !room2) {
            my_printf("ERROR: room `%s` doesn't exist\n", !room1 ? split_str[0] :
                split_str[1]);
            return 84;
        }
        tunnel = malloc(sizeof(tunnel_t));
        tunnel->room1 = room1;
        tunnel->room2 = room2;
        data->tunnels = ll_append(data->tunnels, tunnel);
    }
    return 0;
}

int parse_start_end(lemin_data_t *data, char *line)
{
    if (my_str_startswith(line, "##")) {
        if (!my_strcmp(line, "##start") || !my_strcmp(line, "##end")) {
            data->next_room = !my_strcmp(line, "##start") ? R_START : R_END;
            if ((data->next_room == R_START && data->start_room) ||
                (data->next_room == R_END && data->end_room)) {
                my_printf("ERROR: multiple %s rooms", data->next_room ==
                    R_START ? "start" : "end");
                return my_free_assign(line, 84);
            }
        }
        return my_free_assign(line, 1);
    }
    return 0;
}

int parse_line(lemin_data_t *data)
{
    char *lineptr = NULL;
    size_t n = 0;
    int return_value = getline(&lineptr, &n, stdin);
    char **split_str;

    if (return_value == -1) return my_free_assign(lineptr, -1);
    if (my_strlen(lineptr) != 0 && lineptr[my_strlen(lineptr) - 1] == '\n')
        lineptr[my_strlen(lineptr) - 1] = 0;
    return_value = parse_start_end(data, lineptr);
    if (return_value) return return_value;
    split_str = my_strsplit(lineptr, '#');
    if (!my_strcmp(split_str[0], "")) {
        free_split(split_str);
        return my_free_assign(lineptr, return_value);
    }
    if (data->ants_nb == -999999999) data->ants_nb = my_getnbr(split_str[0]);
    else if (!parse_room(data, split_str[0]))
        return_value = parse_tunnel(data, split_str[0]);
    free_split(split_str);
    return my_free_assign(lineptr, return_value);
}