##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile
##

SRC		=	main.cpp	\
			hostname.cpp	\
			kernel.cpp \
			meminfo.cpp \
			date_time.cpp \
			getName.cpp \
			ncurses.cpp \
			ncurses_display.cpp \
			MyGKrellM.cpp	\
			cpu.cpp	\
			processor.cpp	\
			graphique.cpp	\
			setglobal.cpp \
			network.cpp


OBJ		=	$(SRC:.cpp=.o)

NAME		=	GkrellM

CXX 		= 		g++

CXXFLAGS		+=	-lncurses -Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:		fclean all
