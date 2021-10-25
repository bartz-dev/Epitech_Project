
SRC	=	DoOp.hs	\

CC	=	ghc

CFLAGS	=	-std=gnull -Wall -Wextra

NAME	=	doop

all: $(NAME)

$(NAME):	$(SRC)
		$(CC) $(SRC) -o $(NAME)

clean: 
			rm -f *.hi *.o

fclean: clean
			rm -f doop

re: fclean all