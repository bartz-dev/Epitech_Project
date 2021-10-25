/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** main.c
*/

#include "lemin.h"
#include "stdlib.h"

lemin_data_t *init_data(void)
{
    lemin_data_t *data = malloc(sizeof(lemin_data_t));

    data->rooms = 0;
    data->ants = 0;
    data->ants_nb = -999999999;
    data->end_room = 0;
    data->start_room = 0;
    data->tunnels = 0;
    data->next_room = R_NORMAL;
}

int ants_walk(lemin_data_t *data)
{
    ant_t *ant;
    int ant_nb = 0;
    int iter_nb = 0;
    int remove_previous = 0;

    for (linked_list_t *i = data->ants; i; i = i->next) {
        if (remove_previous) {
            free(ant);
            data->ants = ll_remove(data->ants, ant_nb - 1);
            ant_nb--;
            remove_previous = 0;
        }
        ant = i->data;
        if (!next_room(iter_nb, ant, data)) return 84;
        if (!my_strcmp(ant->current_room, data->end_room)) remove_previous = 1;
        ant_nb++;
        iter_nb++;
    }
    if (remove_previous) {
        free(ant);
        data->ants = ll_remove(data->ants, ant_nb - 1);
    }
    my_printf("\n");
    return 0;
}

int main(int ac, char **av, char **envp)
{
    int line_status = 0;
    lemin_data_t *data = init_data();

    while (line_status != -1 && line_status != 84)
        line_status = parse_line(data);
    if (data->ants_nb < 0) {
        my_printf("ERROR: invalid number of ants");
        return 84;
    }
    if (!data->start_room || !data->end_room) {
        my_printf("ERROR: no %s room", data->start_room ? "end" : "start");
        return 84;
    }
    if (line_status == 84) return 84;
    init_display(data);
    create_ants(data);
    while (data->ants)
        if (ants_walk(data) == 84) break;
    ll_free(data->ants, free);
    dict_free(data->rooms, 1, free);
    free(data);
}