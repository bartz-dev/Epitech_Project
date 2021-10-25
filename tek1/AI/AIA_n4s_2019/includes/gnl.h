/*
** EPITECH PROJECT, 2019
** AIA_n4s_2019
** File description:
** gnl.h
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_
#include <stdlib.h>
#include <stdio.h>

#define SIZE_MALLOC (4096)

typedef struct s_vars {
    int value;
    char *line;
    int id;
    int	id_line;
    char buf[1];
} t_vars;

char *get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
