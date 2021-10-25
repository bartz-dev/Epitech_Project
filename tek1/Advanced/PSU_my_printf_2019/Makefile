##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make automatic gcc command
##

SRC 		=	lib/my/my_getnbr.c	\
			 lib/my/my_putchar.c		\
			 lib/my/my_put_nbr.c	\
			 lib/my/my_putstr.c	\
			 lib/my/my_strcpy.c	\
			 lib/my/my_putfloat.c	\
			 lib/my/my_putdouble.c	\
			 lib/my/my_printf.c	\

FCT		= 	lib/my/my.h	\
			lib/my/struct.h	\

OBJ 		=	$(SRC:.c=.o)

NAME		=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(FCT) include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) include/*

re: fclean all
