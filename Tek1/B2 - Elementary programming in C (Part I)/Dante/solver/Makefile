##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	.

SRC		=	src/get_line.c	\
			src/get_maze.c	\
			src/str_len.c	\
			src/moves.c		\
			src/solve.c		\
			src/free.c		\
			main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	solver

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

set:
	reset