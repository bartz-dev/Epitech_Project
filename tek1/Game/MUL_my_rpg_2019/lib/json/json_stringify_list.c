/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_stringify_list
*/

#include "json.h"
#include "tools.h"

char *json_stringify_list(char *json, json_object_t *data)
{
    char *content = my_strdup("");
    char *final = my_strdup("[");

    UNUSED(json);
    for (json_object_t *i = data->data; i; i = i->next) {
        content = json_stringify_value(content, i);
        if (i->next)
            content = json_stringify_append(content, my_strdup(","));
    }
    final = json_stringify_append(final, content);
    final = my_free_assign(final, my_strconcat(final, "]"));
    return final;
}