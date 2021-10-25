/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-clement.fleur
** File description:
** mem_ptr.c
*/

#include "mem_ptr.h"
#include <string.h>
#include <stdlib.h>

void add_str(const char *str, const char *str2, char **res)
{
    *res = malloc(strlen(str) + strlen(str2) + 1);
    strcpy(*res, str);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    str_op->res = malloc(strlen(str_op->str1) + strlen(str_op->str2) + 1);
    strcpy(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);
}