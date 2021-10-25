##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make automatic gcc command
##

SRC 		=	my_getnbr.c	\
			 	my_putchar.c		\
			 	my_put_nbr.c	\
			 	my_putstr.c	\
			 	my_strcpy.c	\
			 	my_putfloat.c	\
			 	my_putdouble.c	\

FCT		= 	my.h	\
			struct.h	\
			player.h	\

OBJ 		=	$(SRC:.c=.o)

NAME		=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(FCT) ../../include
		cp $(NAME) ../

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) ../../include/*.h ../$(NAME)

re: fclean all
