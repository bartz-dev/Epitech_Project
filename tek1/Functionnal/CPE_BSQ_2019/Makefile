##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make automatic gcc command
##

SRC 		=	lib/my/my_getnbr.c	\
			 lib/my/my_putchar.c		\
			 lib/my/my_put_nbr.c	\
			 lib/my/my_putstr.c	\
			 lib/my/my_strcpy.c	\
			 lib/my/my_printf.c	\
			 lib/my/my_revstr.c	\
			 lib/my/my_str_to_word_array.c	\
			 lib/my/my_strcat.c	\
			 lib/my/my_strconcat.c	\
			 lib/my/my_strdup.c	\
			 lib/my/my_strlen.c	\
			 lib/my/my_strlowcase.c	\
			 lib/my/my_strncmp.c	\
			 lib/my/my_strncpy.c	\
			 lib/my/open_file.c	\
			 lib/my/main.c	\
			 lib/my/my_strtodouble.c	\
			 lib/my/my_strlen2.c	\
			 lib/my/strlen_nb_line.c	\
			 lib/my/strlen_bn.c	\
			 lib/my/error.c	\
			 lib/my/my_check.c	\
			 lib/my/test_tab2.c	\
			 bsq.c	\

FCT		= 	lib/my/my.h	\
			lib/my/struct.h	\

OBJ 		=	$(SRC:.c=.o)

CFLAGS          +=      -W -Wall -Wextra -pedantic                              
CFLAGS          +=      -I./include -L./lib -lmy  

NAME		=	bsq

NAME2		=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
		ar rc lib/$(NAME2) $(OBJ)
		cp $(FCT) include
		gcc -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) lib/$(NAME2) include/*

re: fclean all
