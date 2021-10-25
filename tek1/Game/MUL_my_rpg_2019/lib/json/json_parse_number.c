/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_parse_number
*/

#include "json.h"
#include "tools.h"

void *json_parse_number(char **cur, json_object_t *obj)
{
    int is_float = 0;
    float total = 0;
    char *current = my_strdup("");

    while (((*cur)[0] >= '0' && (*cur)[0] <= '9') || (*cur)[0] == '.') {
        if ((*cur)[0] == '.' && !is_float) {
            is_float = 1;
            obj->type = JSON_DOUBLE;
            total += my_getnbr(current);
            current = my_strdup("");
        } else if ((*cur)[0] == '.' && is_float) {
            my_printf("invalid json\n");
            return 0;
        } else current = my_free_assign(current,
                my_strconcat(current, my_char_to_str((*cur)[0])));
        (*cur)++;
    }
    total += (double) my_getnbr(current) /
        (double) (is_float ? my_compute_power_rec(10, my_strlen(current)) : 1);
    return is_float ? (void *) pdouble(total) : (void *) pint(total);
}