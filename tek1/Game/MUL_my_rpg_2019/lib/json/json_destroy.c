/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_destroy
*/

#include "json.h"
#include <stdlib.h>

void json_destroy(json_object_t *obj)
{
    if (obj->type == JSON_DICT || obj->type == JSON_LIST)
        for (json_object_t *i = obj; i; i = i->next)
            json_destroy(i->data);
    if (obj->type == JSON_DOUBLE || obj->type == JSON_INT ||
        obj->type == JSON_STRING)
        free(obj->data);
    free(obj);
}