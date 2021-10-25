##
## EPITECH PROJECT, 2021
## makefile
## File description:
## do stuff
##

SOURCE	=	source/register.cpp	\
			source/utils.cpp	\
			source/operand.cpp	\
			source/factory.cpp	\
			source/parser.cpp	\
			source/parse_number.cpp \
			source/vm.cpp	\
			source/exception.cpp

MAIN	=	source/main.cpp

NAME	=	abstractVM

OBJ	=	$(SOURCE:.cpp=.o)	\
		$(MAIN:.cpp=.o)

VERSION	=	-std=c++20

CXXFLAGS=	-Wall -Wextra -Werror -pedantic -g3 -O3 $(VERSION)

CPPFLAGS=	-I include/

LDFLAGS	=

all:	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

re:	clean all

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -rf $(OBJ) $(NAME)

.PHONY:	all re clean fclean
