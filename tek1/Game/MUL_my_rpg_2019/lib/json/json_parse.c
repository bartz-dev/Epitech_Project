/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_parse
*/

#include "json.h"
#include "tools.h"
#include <stdlib.h>

json_object_t *json_parse_append(json_object_t *obj, json_object_t *to_append)
{
    json_object_t *i;

    if (!obj) return to_append;
    for (i = obj; i->next; i = i->next);
    i->next = to_append;
    return obj;
}

json_object_t *json_parse_step(char **cursor, json_object_t *obj)
{
    switch((*cursor)[0]) {
        case '{':
            obj->data = json_parse_dict(cursor);
            obj->type = JSON_DICT;
            break;
        case '[':
            obj->data = json_parse_list(cursor);
            obj->type = JSON_LIST;
            break;
        default:
            return print_return("invalid json\n", 0);
    }
    return obj ? obj : print_return("invalid json\n", 0);
}

void *json_parse(char *json)
{
    json_object_t *obj = malloc(sizeof(json_object_t));
    char *trimmed_json = my_trim_keep_str(json);
    char *temp = trimmed_json;

    if (trimmed_json[0] != '[' && trimmed_json[0] != '{') {
        free(trimmed_json);
        free(obj);
        return print_return("invalid json\n", 0);
    }
    obj->next = 0;
    obj->type = JSON_INVALID;
    obj->data = 0;
    obj->index = "";
    obj = json_parse_value(&trimmed_json, obj);
    free(temp);
    return obj ? obj :
        my_free_assign(obj, print_return("invalid json\n", 0));
}