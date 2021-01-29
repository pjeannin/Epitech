##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	src/readmap.c		\
		src/move.c			\
		src/utils.c			\
		src/game.c			\
		src/error_message.c	\
		src/utils_game.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
