/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_parse_dict
*/

#include "json.h"
#include "tools.h"
#include <stdlib.h>

json_object_t *key_value_pair(char **cursor, json_object_t *obj)
{
    char *var_name = 0;

    json_object_t *next_obj = malloc(sizeof(json_object_t));
    next_obj->next = 0;
    while ((*cursor)[0] != ',' && (*cursor)[0] != '}') {
        if ((*cursor)[0] == '"' && !var_name) var_name = (*cursor) + 1;
        else if ((*cursor)[0] == '"' && var_name) {
            (*cursor)[0] = 0;
            next_obj->index = my_strdup(var_name);
        }
        if ((*cursor)[0] == ':') {
            (*cursor)++;
            next_obj = json_parse_value(cursor, next_obj);
            (*cursor)--;
        }
        (*cursor)++;
    }
    if ((*cursor)[0] == ',') (*cursor)++;
    return json_parse_append(obj, next_obj);
}

json_object_t *json_parse_dict(char **cursor)
{
    json_object_t *obj = 0;
    while ((*cursor)[0] != '}') {
        if ((*cursor)[0] == 0) return print_return("invalid json\n", 0);
        obj = key_value_pair(cursor, obj);
    }
    (*cursor)++;
    return obj;
}