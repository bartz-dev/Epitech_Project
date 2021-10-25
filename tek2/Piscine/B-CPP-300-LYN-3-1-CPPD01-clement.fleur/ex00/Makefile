##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPD01-clement.fleur
## File description:
## Makefile
##

SRC		=       z.c

OBJ     =       $(SRC:.c=.o)

NAME    =       z

CFLAGS 	+=      -std=gnu11 -Wall -Wextra

all:            $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -rf $(OBJ) $(NAME)

fclean:	clean

re:	fclean all