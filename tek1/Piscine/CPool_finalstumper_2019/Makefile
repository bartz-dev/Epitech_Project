##
## EPITECH PROJECT, 2019
## rush2
## File description:
## Displays language info
##

SRC		=	finalstumper.c

LIB_MAKE	=	lib/my

OBJ		=	$(SRC:.c=.o)

NAME		=	rush3

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I./include -L./lib -lmy

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
