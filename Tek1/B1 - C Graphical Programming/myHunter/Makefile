##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

SRC	=	src/big_screen.c		\
		src/screen.c			\
		src/screen_bis.c		\
		src/utils.c				\
		src/utils_bis.c			\
		src/utils_end.c			\
		src/event.c				\
		src/event_bis.c			\
		src/event_screen_four.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} $(FLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all