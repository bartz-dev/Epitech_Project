/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json.h
*/

#ifndef JSON_H_
#define JSON_H_

#include "linked.h"

#define JSON_LIST 1
#define JSON_DICT 2
#define JSON_INT 3
#define JSON_DOUBLE 4
#define JSON_STRING 5
#define JSON_INVALID 6

typedef struct json_object {
    void *data;
    void *next;
    char *index;
    int type;
} json_object_t;

json_object_t *json_parse_append(json_object_t *obj, json_object_t *to_append);
char *json_parse_string(char **cursor);
void *json_parse_number(char **cursor, json_object_t *obj);
json_object_t *json_parse_step(char **cursor, json_object_t *obj);
void *json_parse_value(char **cursor, json_object_t *obj);
json_object_t *json_parse_list(char **cursor);
json_object_t *json_parse_dict(char **cursor);
void *json_parse(char *json);
char *json_stringify_dict(char *json, json_object_t *data);
char *json_stringify_double(json_object_t *data);
char *json_stringify_list(char *json, json_object_t *data);
char *json_stringify_string(char *data);
char *json_stringify_value(char *json, json_object_t *data);
char *json_stringify_step(char *json, json_object_t *data);
char *json_stringify(json_object_t *data);
char *json_stringify_append(char *json, char *to_append);
json_object_t *read_json(char *filename);
void json_destroy(json_object_t *obj);

#endif /* !JSON_H_ */