##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		my_getnbr.c	\
		first_char.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		rush3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: 	fclean all
