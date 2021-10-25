##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make automatic gcc command
##

SRC 		=	 my_compute_power_rec.c	\
			 my_compute_square_root.c	\
			 my_find_prime_sup.c	\
			 my_getnbr.c	\
			 my_isneg.c	\
			 my_is_prime.c	\
			 my_putchar.c		\
			 my_put_nbr.c	\
			 my_putstr.c	\
			 my_revstr.c	\
			 my_show_word_array.c	\
			 my_strcat.c	\
			 my_strcmp.c	\
			 my_strcpy.c	\
			 my_strdup.c	\
			 my_strlen.c	\
			 my_strlowcase.c	\
			 my_strncat.c	\
			 my_strncpy.c	\
			 my_strstr.c	\
			 my_str_to_word_array.c	\
			 my_strupcase.c	\
			 my_swap.c	\
			 my_arrlen.c	\
			 my_putfloat.c	\
			 my_putdouble.c	\
			 my_xor.c	\
			 my_max.c	\
			 my_strslice.c	\
			 my_strsplit.c	\
			 my_strconcat.c	\
			 my_int_to_str.c	\
			 pointer_display.c	\
			 my_printf.c	\
			 vectors.c	\
			 my_str_startswith.c	\
			 my_read_file.c	\
			 my_strtrimwhitesp.c	\
			 my_free_assign.c	\
			 my_char_to_str.c	\
			 stripslashes.c	\
			 addslashes.c	\
			 my_strncmp.c	\
			 my_str_isnum.c	\
			 my_str_endswith.c	\
			 random.c	\
			 my_strjoin.c	\

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I../../include

OBJ 		=	$(SRC:.c=.o)

NAME		=	libtools.a

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@if test -s $*.c; then \
		echo -e "\033[00m\033[36m [LIBTOOLS]\033[01m\033[35m Compiling \
		\033[00m\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
		else \
		echo -e "\033[00m\033[36m [LIBTOOLS]\033[01m\033[35m Compiling \
		\033[00m\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

all: 	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) ../$(NAME)
