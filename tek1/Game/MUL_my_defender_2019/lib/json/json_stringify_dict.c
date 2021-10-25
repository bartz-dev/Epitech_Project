/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_stringify_dict
*/

#include "json.h"
#include "tools.h"

char *json_stringify_dict(char *json, json_object_t *data)
{
    char *content = my_strdup("");
    char *final = my_strdup("{");

    UNUSED(json);
    for (json_object_t *i = data->data; i; i = i->next) {
        content = json_stringify_append(content,
            json_stringify_string(i->index));
        content = my_free_assign(content, my_strconcat(content, ":"));
        content = json_stringify_value(content, i);
        if (i->next)
            content = json_stringify_append(content, my_strdup(","));
    }
    final = json_stringify_append(final, content);
    final = my_free_assign(final, my_strconcat(final, "}"));
    return final;
}