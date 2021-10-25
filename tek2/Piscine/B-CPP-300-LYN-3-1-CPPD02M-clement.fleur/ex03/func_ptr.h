/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02M-clement.fleur
** File description:
** func_ptr.h
*/

#include "func_ptr_enum.h"

typedef struct action_exec_s
{
    action_t flag;
    void (*fct) (const char *);
} action_exec_t;
