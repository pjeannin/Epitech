##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_putstr.c \
		my_put_nbr.c	\
		my_putchar.c	\
		isnum.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_revstr.c	\
		my_find_len.c	\
		error.c	\
		my_strcmp.c	\
		rem_neg.c	\
		sub.c	\
		compute_sub.c	\
		sub_compute.c	\
		bigger1.c	\
		comp.c	\
		add.c	\
		init.c	\
		remove_0.c	\
		compute.c	\
		compute_1.c	\
		compute_2.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: 	fclean all