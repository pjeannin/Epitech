##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: 	fclean all