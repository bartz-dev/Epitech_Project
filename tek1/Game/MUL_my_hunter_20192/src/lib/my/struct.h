/*
** EPITECH PROJECT, 2019
** struct
** File description:
** 
*/

#ifndef PRINT_H_
#define PRINT_H_

struct printf_a
{
    char *flag;
    void (*fct) (void*);
};

typedef struct printf_a print;

#endif /* PRINT_H_ */