##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

LIB	=	lib/my_putchar.c \
		lib/base.c \
		lib/my_char_isalpha.c	\
		lib/my_getnbr.c \
		lib/my_printf.c 	\
		lib/my_put_long.c	\
		lib/my_put_nbr.c \
		lib/my_putnprintable.c 	\
		lib/my_putstr.c \
		lib/my_str_isalpha.c 	\
		lib/my_str_isprintable.c 	\
		lib/my_strlen.c 	\
		lib/my_put_unsigned_long.c	\
		lib/my_put_unsinged_int.c 	\
		lib/hexa_base.c	\
		lib/hexa_base_upper.c 	\
		lib/hexa_base_long.c	\
		lib/base_long.c	\
		lib/isnum.c	\
		lib/char_isalpha.c	\

SRC = 	main.c 	\
		sources/error/error_handling.c	\
		sources/error/pos_error.c	\
		sources/error/check_collision.c	\
		sources/error/mapchecking.c	\
		sources/memory.c	\
		sources/utils.c	\
		sources/print_map.c	\
		sources/help.c	\
		sources/client.c 	\
		sources/server.c 	\
		sources/navy.c 	\
		sources/destroy.c 	\
		sources/game.c	\
		sources/get_sig.c	\
		sources/attack.c

CFLAGS	=	-I ./includes/ -g3

OBJ	= 	$(LIB:.c=.o)	\
		$(SRC:.c=.o)

CC = @gcc

NAME	=	navy

all:		$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@echo CLEAN

fclean: clean
	@rm -f $(NAME)
	@echo FCLEAN

re:	fclean all
	@echo RE