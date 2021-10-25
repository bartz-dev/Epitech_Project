##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_sokoban compile
##

SRC		=	main.c	\
			src/my_ls.c \
			src/check.c \
			src/shorter.c	\
			src/l_flag.c	\
			src/no_flag.c

LIB_MAKE	=	lib/my

OBJ		=	$(SRC:.c=.o)

NAME		=	my_ls

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=  -I./include -L./lib -lmy

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
		rm -f $(NAME) include/*

re:		fclean all
