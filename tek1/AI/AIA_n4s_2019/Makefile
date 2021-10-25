##
## EPITECH PROJECT, 2019
## makefile
## File description:
## my_sokoban compile
##

SRC		=	src/ia.c \
			src/get_next_line.c \
			src/utils.c	\
			src/command.c	\
			src/my_strtotab.c \
			src/car.c

LIB_MAKE	=	lib/my

OBJ		=	$(SRC:.c=.o)

NAME		=	ai

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=  -I./includes

all:		$(NAME)

$(NAME): $(OBJ)
		@echo -e "\033[01m\033[31m----------------- Building ...---------------\033[00m"
		gcc -o $(NAME) $(OBJ) $(CFLAGS)
		@echo -e "\033[32;01m[-------------------Succes-------------------\033[00m"


clean:
		rm -f $(NAME)
		@echo -e "\033[01m\033[31m-----------------Cleaning all objects---------------\033[00m"

fclean:		clean
			rm -f  $(OBJ)
			@echo -e "\033[01m\033[31m--------------------Binary clean--------------------\033[00m"

re:		fclean all
