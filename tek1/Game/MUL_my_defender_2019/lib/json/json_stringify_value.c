/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_stringify_value
*/

#include "json.h"
#include "tools.h"

char *json_stringify_value(char *json, json_object_t *data)
{
    switch (data->type) {
        case JSON_INT:
            json = json_stringify_append(json,
                my_int_to_str(*(int *)(data->data)));
            break;
        case JSON_DOUBLE:
            json = json_stringify_append(json,
                json_stringify_double(data));
            break;
        case JSON_STRING:
            json = json_stringify_append(json,
                json_stringify_string(data->data));
            break;
        default:
            json = json_stringify_step(json, data);
    }
    return json;
}