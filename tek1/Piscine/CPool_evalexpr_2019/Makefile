##
## EPITECH PROJECT, 2019
## rush2
## File description:
## Displays language info
##

SRC		=	my_rmspace.c	\
			eval_expr.c	\

LIB_MAKE	=	lib/my

OBJ		=	$(SRC:.c=.o)

NAME		=	eval_expr

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
