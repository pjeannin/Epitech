##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/my_printf.c			\
		src/utils.c	\
		src/put_str.c	\
		src/base_convert.c	\
		src/put_all_nbr.c	\
		src/put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -c $(OBJ)
		ar rc $(NAME) src/*.o

clean:	
		rm -f src/*.o

fclean:	clean
		rm $(NAME)

re:	fclean all
