##
## EPITECH PROJECT, 2019
## folder_name
## File description:
## Makefile
##

NAME    =   corewar

SRC     =   src/main.c \

CC		=	gcc

MK		=	make --no-print-directory

RM		=	rm -f

CFLAGS	+=	-Iinclude/ -L../lib/phoenix/ -lphoenix

CURSES += -l ncurses

OBJ     =   $(SRC:.c=.o)

$(OBJDIR)%.o:		%.c
			@$(CC) $(CFLAGS) -o $@ -c $<
			@if test -s $*.c; then \
			echo -e "\033[01m\033[35m Compiling \033[00m\
			\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
			else \
			echo -e "\033[01m\033[33m Compiling \033[00m\
			\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

$(NAME):	$(OBJ)
			@echo -e "\033[01m\033[31mBuilding...\033[00m"
			@$(MK) -C lib/phoenix/
			@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
			@echo -e "\033[01m\033[32mCompilation done: ${NAME}\033[00m"

all:		$(NAME)

clean:
			@$(RM) $(OBJ)
			@echo -e "\033[01m\033[31mRemoving objects...\033[00m"
			@$(MK) clean -C lib/phoenix/

fclean:		clean
			@$(RM) $(NAME)
			@echo -e "\033[01m\033[31mRemoving binary: ${NAME}\033[00m"
			@$(MK) fclean -C lib/phoenix/

re:			fclean all