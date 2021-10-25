##
## EPITECH PROJECT, 2020
## libjson
## File description:
## Makefile
##

SRC			=	json_parse.c	\
				json_parse_dict.c	\
				json_parse_list.c	\
				json_parse_number.c	\
				json_parse_string.c	\
				json_parse_value.c	\
				json_stringify.c	\
				json_stringify_value.c	\
				json_stringify_string.c	\
				json_stringify_double.c	\
				json_stringify_dict.c	\
				json_stringify_list.c	\
				json_destroy.c	\
				read_json.c	\

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I../../include

OBJ 		=	$(SRC:.c=.o)

NAME		=	libjson.a

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@if test -s $*.c; then \
		echo -e "\033[00m\033[36m [LIBJSON]\033[01m\033[35m Compiling \
		\033[00m\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
		else \
		echo -e "\033[00m\033[36m [LIBJSON]\033[01m\033[35m Compiling \
		\033[00m\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

all: 	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) ../$(NAME)
