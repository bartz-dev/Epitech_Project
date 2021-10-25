/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD02A-clement.fleur
** File description:
** stack.c
*/

#include "generic_list.h"
#include "stack.h"

unsigned int stack_get_size(stack_t stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t stack)
{
    return list_is_empty(stack);
}

bool stack_push(stack_t *stack_ptr, void *elem)
{
    return list_add_elem_at_front(stack_ptr, elem);
}

bool stack_pop(stack_t *stack_ptr)
{
    list_get_elem_at_back(*stack_ptr);
    return list_del_elem_at_back(stack_ptr);
}

void *stack_top(stack_t stack)
{
    if (!stack)
        return 0;
    return stack->value;
}