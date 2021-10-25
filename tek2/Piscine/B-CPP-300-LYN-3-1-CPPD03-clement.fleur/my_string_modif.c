/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD03-clement.fleur
** File description:
** my_strmodif.c
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (!this || !str || !this->str)
        return;
    free(this);
    this->str = strdup(str->str);
}

void assign_c(string_t *this, const char *s)
{
    if (!this || !this->str || !s)
        return;
    free(this);
    this->str = strdup(s);
}

void append_s(string_t *this, const string_t *ap)
{
    char *s1 = strdup(this->str);
    char *s2 = strdup(ap->str);

    free(this->str);
    this->str = malloc(sizeof(char) * strlen(s1) + strlen(s2) + 2);
    this->str[0] = '\0';

    strcat(this->str, s1);
    strcat(this->str, s2);

    free(s1);
    free(s2);
}

void append_c(string_t *this, const char *ap)
{
    char *s1 = strdup(this->str);
    free(this->str);
    this->str = malloc(sizeof(char) * strlen(s1) + strlen(ap) + 2);
    this->str[0] = '\0';

    strcat(this->str, s1);
    strcat(this->str, ap);

    free(s1);
}

char at(const string_t *this, size_t pos)
{
    unsigned int size = strlen(this->str) - 1;

    if (!this || !this->str)
        return -1;
    return pos <= size ? this->str[pos] :  -1;
}