##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_sokoban compile
##

SRC		=	main.c	\
			src/utils.c	\

OBJ		=	$(SRC:.c=.o)

NAME		=	tetris

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-lncurses -I./include -L./lib -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean

re:		fclean all
