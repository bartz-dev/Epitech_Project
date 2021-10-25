/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include "tools.h"

int is_in(char c, char a, char z)
{
    return (c >= a && c <= z);
}

void add_string_to_arr(char *str, char **arr, int *start, counter_t *count)
{
    str[count->i] = '\0';

    arr[count->j] = str + *start;
    (count->j)++;
    *start = count->i + 1;
}

void calculate_array_size(char *str, counter_t count, int *size)
{
    while (str[count.i])
    {
        if (!is_in(str[count.i], 'a', 'z') && !is_in(str[count.i], 'A', 'Z')
            && !is_in(str[count.i], '0', '9'))
            (*size)++;
        count.i++;
    }
}

char **my_str_to_word_array(char const *str)
{
    char *new_str = my_strdup(str);
    int size = 0;
    int start = 0;
    char **arr;
    counter_t count;
    count.i = 0;
    count.j = 0;

    calculate_array_size(new_str, count, &size);
    count.i = 0;
    arr = malloc(sizeof(char *) * size + 1);
    while (new_str[count.i]) {
        if (!is_in(str[count.i], 'a', 'z') && !is_in(str[count.i], 'A', 'Z')
            && !is_in(str[count.i], '0', '9'))
            add_string_to_arr(new_str, arr, &start, &count);
        count.i++;
    }
    add_string_to_arr(new_str, arr, &start, &count);
    arr[count.j + 1] = 0;
    return (arr);
}
