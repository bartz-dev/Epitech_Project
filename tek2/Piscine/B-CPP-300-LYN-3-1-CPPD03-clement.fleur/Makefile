##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPD01-clement.fleur
## File description:
## Makefile
##

SRC             =		my_string.c	\
						my_string_modif.c	\
						my_string_compare.c

OBJ             =       $(SRC:.c=.o)

FCT				=		string.h

NAME            =       libstring.a

CFLAGS          +=      -std=gnu11 -Wall -Wextra

all:            $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ) $(NAME)

fclean:	clean

re:	fclean all