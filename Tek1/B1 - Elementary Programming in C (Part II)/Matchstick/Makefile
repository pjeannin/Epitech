##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	src/error_handling.c	\
		src/my_getnbr.c			\
		src/print_game_board.c	\
		src/tab_utils.c			\
		src/update_game_board.c	\
		src/utils.c				\
		src/check_end.c			\
		src/get_input.c			\
		src/player.c			\
		src/ai.c				\
		src/matchstick.c		\
		src/display.c			\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS}

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all