##
## EPITECH PROJECT, 2019
## folder
## File description:
## Makefile
##

NAME    =   libphoenix.a

SRC     =   is_prime_number.c \
			my_putchar.c \
			my_strcpy.c \
			my_strncmp.c \
			my_strstr.c \
			my_revstr.c \
			my_putnbr.c \
			my_putstr.c \
			to_number.c \
			concat_strings.c \
			my_strcmp.c

OBJ     =   $(SRC:.c=.o)

$(OBJDIR)%.o:		%.c
			@$(CC) $(CFLAGS) -o $@ -c $<
			@if test -s $*.c; then \
			echo -e "\033[01m\033[35m Compiling \033[00m\
			\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
			else \
			echo -e "\033[01m\033[33m Compiling \033[00m\
			\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

CFLAGS	+=	-I../../include/

CP		=	cp ../../include/phoenix.h phoenix.h

AR		=	ar rc

CC		=	gcc

RM		=	rm -f

$(NAME):	$(OBJ)
	@echo -e "\033[01m\033[31mBuilding phoenix lib...\033[00m"
	@$(CP)
	@$(AR) $(NAME) $(OBJ)
	@echo -e "\033[01m\033[32mCompilation done: ${NAME}\033[00m"

all:	$(NAME)

clean:
		@$(RM) $(OBJ)
		@echo -e "\033[01m\033[31mRemoving library objects...\033[00m"

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) phoenix.h
		@echo -e "\033[01m\033[31mRemoving library: ${NAME}\033[00m"

re:	fclean all
