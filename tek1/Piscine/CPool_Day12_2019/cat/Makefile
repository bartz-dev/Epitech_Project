##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## by clement fleur
##

SRC	=	my_putstr.c	\
		my_putchar.c	\
		cat.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
