/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_stringify_string
*/

#include "json.h"
#include "tools.h"

char *json_stringify_string(char *data)
{
    char *to_return = my_strdup("\"");
    char *slashes = addslashes(data);

    to_return = json_stringify_append(to_return, slashes);
    to_return = my_free_assign(to_return, my_strconcat(to_return, "\""));
    return to_return;
}