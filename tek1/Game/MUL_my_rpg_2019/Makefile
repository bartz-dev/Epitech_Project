##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Builds the project
##

CC	=	gcc

RM	=	rm -f

MK	=	make --no-print-directory

SRC		=	src/main.c	\
			src/misc/loading_zones.c	\
			src/misc/text.c	\
			src/quest/import.c	\
			src/quest/render.c	\
			src/quest/progress.c	\
			src/player/movement.c	\
			src/dialogue/import.c	\
			src/dialogue/start.c	\
			src/dialogue/free.c	\
			src/dialogue/entity_dialogue.c	\
			src/dialogue/render.c	\
			src/dialogue/progress.c	\
			src/menus/principal.c	\
			src/menus/pause.c \
			src/fight/pve1.c \
			src/fight/pve2.c \
			src/fight/start.c \
			src/fight/render.c

OBJ		=	$(SRC:.c=.o)

NAME		=	my_rpg

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I./include -L./lib

LIBTOOLS	=	-l tools

LIBLINKED	=	-l linked

LIBJSON		=	-l json

LIBGAME		=	-l game	\
				-l csfml-graphics	\
				-l csfml-audio	\
				-l csfml-system	\
				-l csfml-window	\
				-l csfml-network

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@if test -s $*.c; then \
		echo -e "\033[01m\033[35m Compiling \033[00m\
		\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
		else \
		echo -e "\033[01m\033[33m Compiling \033[00m\
		\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

all:		game linked json tools $(NAME)

$(NAME):	$(OBJ)
		@echo -e "\033[01m\033[31mBuilding...\033[00m"
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		@echo -e "\033[01m\033[32mCompilation done: ${NAME}\033[00m"

tools:
		$(eval CFLAGS += $(LIBTOOLS))
		@$(MK) -C lib/tools
game:
		$(eval CFLAGS += $(LIBGAME))
		@$(MK) -C lib/game
linked:
		$(eval CFLAGS += $(LIBLINKED))
		@$(MK) -C lib/linked
json:
		$(eval CFLAGS += $(LIBJSON))
		@$(MK) -C lib/json

tools_clean:
		@echo -e "\033[01m\033[31mCleaning libtools...\033[00m"
		@$(MK) -C lib/tools clean
game_clean:
		@echo -e "\033[01m\033[31mCleaning libgame...\033[00m"
		@$(MK) -C lib/game clean
linked_clean:
		@echo -e "\033[01m\033[31mCleaning liblinked...\033[00m"
		@$(MK) -C lib/linked clean
json_clean:
		@echo -e "\033[01m\033[31mCleaning libjson...\033[00m"
		@$(MK) -C lib/json clean

tools_fclean:
		@$(MK) -C lib/tools fclean
game_fclean:
		@$(MK) -C lib/game fclean
linked_fclean:
		@$(MK) -C lib/linked fclean
json_fclean:
		@$(MK) -C lib/json fclean

debug:	game linked json tools $(OBJ)
		@echo -e "\033[01m\033[31mBuilding...\033[00m"
		@$(CC) -g3 $(SRC) $(CFLAGS)
		@echo -e "\033[01m\033[32mCompilation done: ${NAME}\033[00m"

clean:	game_clean linked_clean json_clean tools_clean
		@echo -e "\033[01m\033[31mCleaning objects...\033[00m"
		@$(RM) $(OBJ)

fclean:		clean game_fclean linked_fclean json_fclean tools_fclean
		@echo -e "\033[01m\033[31mCleaning binary...\033[00m"
		@$(RM) $(NAME)

re:		fclean all