##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	.

SRC	=	main.c			\
		menger.c		\
		drawing.c		\
		bitmap_header.c

OBJ	=	$(SRC:.c=.o)

NAME	=	menger_face

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) 

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} -Wall -Wextra -std=gnu11

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all