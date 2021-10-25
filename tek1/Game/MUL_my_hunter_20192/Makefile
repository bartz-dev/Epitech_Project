##
## EPITECH PROJECT, 2019
## rush2
## File description:
## Displays language info
##

SRC		=	src/display_window.c	\
			src/main.c	\
			src/init.c	\

LIB_MAKE	=	src/lib/my

OBJ		=	$(SRC:.c=.o)

NAME		=	duc

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I./src/include -L./src/lib -lmy -l csfml-graphics

all:		$(NAME)

$(NAME):	build_lib $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C $(LIB_MAKE) libmy.a

clean:
		make -C $(LIB_MAKE) clean
		rm -f $(OBJ)

fclean:		clean
		make -C $(LIB_MAKE) fclean
		rm -f $(NAME)

re:		fclean all
