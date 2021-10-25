##
## EPITECH PROJECT, 2020
## libgame
## File description:
## Makefile
##

SRC			=	my_framebuffer.c	\
				my_putpixel.c	\
				my_create_sprite_from_file.c	\
				my_create_window.c	\
				create_int_rect.c	\
				animation.c	\
				animation2.c	\
				entity.c	\
				sf_vectors.c	\
				game_window.c	\
				tileset.c	\
				layer.c	\
				parallax.c	\
				entity2.c	\
				entity3.c	\
				map.c	\
				hitbox.c	\
				hitbox2.c	\
				destroy.c	\

CFLAGS		+=	-W -Wall -Wextra -pedantic
CFLAGS		+=	-I../../include

OBJ 		=	$(SRC:.c=.o)

NAME		=	libgame.a

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<
		@if test -s $*.c; then \
		echo -e "\033[00m\033[36m [LIBGAME]\033[01m\033[35m Compiling \033[00m\
		\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
		else \
		echo -e "\033[00m\033[36m [LIBGAME]\033[01m\033[35m Compiling \033[00m\
		\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

all: 	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) ../$(NAME)
