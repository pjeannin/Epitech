##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=		generator/src/backtracking_generation.c		\
				generator/src/error_handling.c				\
				generator/src/is_not_a_num.c				\
				generator/src/str_comp.c					\
				generator/src/str_len.c						\
				generator/src/back_step.c					\
				generator/src/no_more_moves.c				\
				generator/src/moves.c						\
				generator/src/create_hole.c					\
				generator/src/map_utils.c					\
				generator/src/restart_map_generation.c		\
				generator/src/create_end.c					\
				generator/main.c

OBJ		=		$(SRC:.c=.o)

NAME	=		generator/generator

SRC2	=		solver/src/get_line.c	\
				solver/src/get_maze.c	\
				solver/src/str_len.c	\
				solver/src/moves.c		\
				solver/src/solve.c		\
				solver/src/free.c		\
				solver/main.c

OBJ2	=		$(SRC2:.c=.o)

NAME2	=		solver/solver

all:	$(OBJ) $(OBJ2)
		gcc -o $(NAME) $(OBJ)
		gcc -o $(NAME2) $(OBJ2)

clean:
			rm -f $(OBJ)
			rm -f $(OBJ2)

fclean:		clean
			rm -f $(NAME)
			rm -f $(NAME2)

re:		fclean all