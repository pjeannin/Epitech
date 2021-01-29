##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	lib/my_getnbr.c	\
		lib/put.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
