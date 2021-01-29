##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	main.c				\
		error_handling.c

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	gcc -g -o $(NAME) $(OBJ) -I${DEPS} -lm 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
