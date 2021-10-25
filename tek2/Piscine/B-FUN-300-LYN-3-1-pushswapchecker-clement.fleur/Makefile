SRC	=	push_swap.hs	\

CC	=	ghc

CFLAGS	=	-std=gnull -Wall -Wextra

NAME	=	pushswap_checker

all: $(NAME)

$(NAME):	$(SRC)
		$(CC) $(SRC) -o $(NAME)

clean:
			rm -f *.hi *.o

fclean: clean
			rm -f pushswap_checker

re: fclean all