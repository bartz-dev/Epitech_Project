/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-clement.fleur
** File description:
** my_string_compare.c
*/

#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    if (!this || !this->str || !str->str)
        return -1;
    return strcmp(this->str, str->str);
}

int compare_c(const string_t *this, const char *str)
{
    if (!this || !this->str || !str)
        return -1;
    return strcmp(this->str, str);
}