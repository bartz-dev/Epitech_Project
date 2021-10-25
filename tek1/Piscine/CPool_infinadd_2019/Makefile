##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## by clement fleur
##

SRC	=	lib/my/my_strlen.c \
		lib/my/my_putstr.c \
		lib/my/my_revstr.c \
		infin_add.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
