##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	my_put_nbr.c	\
		my_putstr.c	\
		my_putchar.c	\
		is_alpha.c	\
		count_str.c	\
		compute_freq.c	\
		compute_freq_bis.c	\
		nb_letter.c	\
		nb_lettr_bis.c	\
		err.c	\
		dis_res.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush2

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: 	fclean all
