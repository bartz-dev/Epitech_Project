##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_sokoban compile
##

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

NAME		=	fizzbuzz

CFLAGS		+=	-W -Wall -Wextra -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
			rm $(NAME)

re:		fclean all
