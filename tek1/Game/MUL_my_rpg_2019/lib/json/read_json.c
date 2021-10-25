/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** read_json
*/

#include "json.h"
#include "tools.h"

json_object_t *read_json(char *filename)
{
    char *content = read_file(filename);

    if (!content) {
        my_printf("JSON Error: File not found: %s\n", filename);
        return 0;
    }
    return my_free_assign(content, json_parse(content));
}