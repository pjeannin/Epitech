##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	.

SRC	=	src/backtracking_generation.c	\
		src/error_handling.c			\
		src/is_not_a_num.c				\
		src/str_comp.c					\
		src/str_len.c					\
		src/back_step.c					\
		src/no_more_moves.c				\
		src/moves.c						\
		src/create_hole.c				\
		src/map_utils.c					\
		src/restart_map_generation.c	\
		src/create_end.c				\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

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