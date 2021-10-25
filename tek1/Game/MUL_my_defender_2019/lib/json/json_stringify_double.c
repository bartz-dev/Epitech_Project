/*
** EPITECH PROJECT, 2020
** libjson
** File description:
** json_stringify_double
*/

#include "json.h"
#include "tools.h"
#include <stdlib.h>

char *json_stringify_double(json_object_t *data)
{
    double d = *(double *)(data->data);
    int power_of_ten = get_power_of_ten(6);
    int must_be_rounded_up = (int)(d * power_of_ten * 10) % 10 >= 5;
    int digits = (int)(d * power_of_ten) % power_of_ten;
    int i = digits;
    char *final = my_int_to_str(d);
    char *decimals;

    final = my_free_assign(final, my_strconcat(final, "."));
    while (6 > get_number_of_digits(i)) {
        final = my_free_assign(final, my_strconcat(final, "0"));
        i = i == 0 ? 10 : i * 10;
    }
    while (must_be_rounded_up == 0 && digits % 10 == 0) {
        digits /= 10;
    }
    decimals = my_int_to_str(digits + must_be_rounded_up);
    final = my_free_assign(final, my_strconcat(final, decimals));
    free(decimals);
    return final;
}