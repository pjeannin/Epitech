##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	Main.hs

OBJ		=	$(SRC:.hs=.hi)
OBJ2	=	$(SRC:.hs=.o)

NAME	=	pushswap_checker

all:
	ghc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ) $(OBJ2) Operation.hi Operation.o

fclean:	clean
	rm -f $(NAME)

re: 	fclean all