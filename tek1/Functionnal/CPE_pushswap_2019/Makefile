##
## EPITECH PROJECT, 2019
## pushswap
## File description:
## Makefile
##

SRC	=	lib/main.c \
		lib/my_engine.c \
		lib/my_get.c \
		lib/my_put.c \
		lib/my_sorter_basics.c \
		lib/my_sorter_move.c \
		lib/my_sorter_rotation.c \
		lib/my_sorter.c \
		lib/my_string.c	\
		lib/my_put_nbr.c	\
		lib/my_putstr.c	\
		lib/my_putchar.c

CFLAGS	=	-Wall -Wextra

INCLUDE =	-I include -o

LIB	=	-g -lm

NAME	=	push_swap

all:	$(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
