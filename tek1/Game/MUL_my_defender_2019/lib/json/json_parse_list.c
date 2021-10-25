/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_parse_list
*/

#include "json.h"
#include "tools.h"
#include "stdlib.h"

json_object_t *json_parse_list(char **cursor)
{
    json_object_t *obj = 0;
    json_object_t *new_obj;

    (*cursor)++;
    while ((*cursor)[0] != ']') {
        if ((*cursor)[0] == 0)
            return print_return("invalid json\n", 0);
        if ((*cursor)[0] == ',') {
            (*cursor)++;
            continue;
        }
        new_obj = malloc(sizeof(json_object_t));
        new_obj->index = "";
        new_obj->type = JSON_INVALID;
        new_obj->next = 0;
        if ((*cursor)[0] == 0) return print_return("invalid json\n", 0);
        obj = json_parse_append(obj, json_parse_value(cursor, new_obj));
    }
    (*cursor)++;
    return obj;
}