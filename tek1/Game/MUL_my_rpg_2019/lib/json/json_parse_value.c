/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_parse_value
*/

#include "json.h"
#include "tools.h"

void *json_parse_value(char **cursor, json_object_t *obj)
{
    if ((*cursor)[0] >= '0' && (*cursor)[0] <= '9') {
        obj->type = JSON_INT;
        obj->data = json_parse_number(cursor, obj);
    } else if ((*cursor)[0] == '"') {
        obj->type = JSON_STRING;
        obj->data = json_parse_string(cursor);
    } else {
        obj = json_parse_step(cursor, obj);
    }
    return obj;
}