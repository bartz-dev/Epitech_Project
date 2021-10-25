/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-clement.fleur
** File description:
** my_string.c
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
}

void string_destroy(string_t *this)
{
    free(this->str);
}

void clear(string_t *this)
{
    memset(this->str, 0, 0);
}

int size(const string_t *this)
{
    if (!this || !this->str)
        return -1;
    return strlen(this->str);

}