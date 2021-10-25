/*
** EPITECH PROJECT, 2019
** struct
** File description:
** 
*/

#ifndef PRINT_H_
#define PRINT_H_

typedef struct	s_bsq
{
    int	i;
    int	count;
    int	tmp;
    int	tmpwidth;
    int	tmplenght;
    int	len;
    int wid;
    int	x;
    int y;
}		t_bsq;

struct printf_a
{
    char *flag;
    void (*fct) (void*);
};

typedef struct printf_a print;

#endif /* PRINT_H_ */

#ifndef STACK_SIZE_H_
#define STACK_SIZE_H_

struct stack_size
{
    int x;
    int y;
    int x2;
    int y2;
};


#endif /* STACK_SIZE_H_ */
