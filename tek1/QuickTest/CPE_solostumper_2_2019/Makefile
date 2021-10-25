##
## EPITECH PROJECT, 2020
## palindrome
## File description:
## 
##

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

NAME		=	palindrome

CFLAGS		+=	-W -Wall -Wextra -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
			rm palindrome

re:		fclean all
