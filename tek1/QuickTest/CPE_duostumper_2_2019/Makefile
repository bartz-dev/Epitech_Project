##
## EPITECH PROJECT, 2020
## 
## File description:
## 
##

NAME	= duostumper

CC	= gcc

RM	= rm -f

SRCS	= ./src/checkword.c \
	  ./src/findword.c \
	  ./src/game.c \
	  ./src/main.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./inc/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
