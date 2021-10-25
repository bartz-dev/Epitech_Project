##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_sokoban compile
##

SRC		=	main.c	\
			requirement.c	\
			src/utils.c	\
			src/help.c	\
			src/my_getnbr.c	\
			src/palindrome.c	\
			src/infinadd.c	\
			src/option.c	\
			src/palindromic.c	\
			src/error.c

LIB_MAKE	=	lib/my

OBJ		=	$(SRC:.c=.o)

NAME		=	palindrome

CFLAGS		+=	-W -Wall -Wextra -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ) $(NAME)

fclean:		clean

re:		fclean all
