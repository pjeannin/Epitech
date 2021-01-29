##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	src/ai.c		\
		src/lidar.c		\
		src/str_utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

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