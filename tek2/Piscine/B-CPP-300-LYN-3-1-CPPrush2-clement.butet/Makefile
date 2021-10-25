##
## EPITECH PROJECT, 2019
## CPE_corewar_2019
## File description:
## Makefile
##

SRC     =		Wrap/Box.cpp 				\
				Elf/ConveyorBelt.cpp			\
				Elf/Elf.cpp						\
				Wrap/GiftPaper.cpp			\
				Objects/LitllePony.cpp		\
				Objects/Object.cpp 			\
				Objects/Teddy.cpp			\
				Objects/Toy.cpp 			\
				Wrap/Wrap.cpp 				\
				main1.cpp



NAME    =		santa_claus


OBJ		=		$(SRC:.cpp=.o)

CFLAGS  =		-Wall -Wextra -Werror -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re