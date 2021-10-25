/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_stringify
*/

#include "json.h"
#include "tools.h"
#include <stdlib.h>

char *json_stringify_append(char *json, char *to_append)
{
    json = my_free_assign(json, my_strconcat(json, to_append));
    free(to_append);
    return json;
}

char *json_stringify_step(char *json, json_object_t *data)
{
    if (data->type == JSON_DICT) {
        json = json_stringify_append(json, json_stringify_dict(json, data));
    } else if (data->type == JSON_LIST) {
        json = json_stringify_append(json, json_stringify_list(json, data));
    } else {
        json = my_free_assign(json, my_strdup("invalid json"));
    }
    return json;
}

char *json_stringify(json_object_t *data)
{
    return json_stringify_value(my_strdup(""), data);
}