##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_putstr.c \
		my_getnbr.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	do_op

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: 	fclean all