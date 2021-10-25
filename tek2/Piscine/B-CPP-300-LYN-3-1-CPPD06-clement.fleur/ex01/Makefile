##
## EPITECH PROJECT, 2020
## B-CPP-300-LYN-3-1-CPPD01-clement.fleur
## File description:
## Makefile
##

SRC		=      	my_temp.cpp	\

OBJ     =       $(SRC:.cpp=.o)

NAME    =       my_convert_temp

CFLAGS 	+=      -Wall -Wextra -Werror

all:            $(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -rf $(OBJ) $(NAME)

fclean:	clean

re:	fclean all