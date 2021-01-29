##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g

SRC	=	src/background.c	\
		src/read_map.c		\
		src/my_getnbr.c		\
		src/my_revstr.c		\
		src/char_from_int.c	\
		src/check_col.c		\
		src/check_end.c		\
		src/find_sol.c		\
		src/game_over.c		\
		src/game.c			\
		src/init_game_struct.c	\
		src/jump.c				\
		src/level.c				\
		src/map.c				\
		src/menu.c				\
		src/move_beginning.c	\
		src/move_elem.c			\
		src/rules.c				\
		src/set_list.c			\
		src/set_text.c			\
		src/image.c				\
		src/win.c				\
		src/creat_window.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all