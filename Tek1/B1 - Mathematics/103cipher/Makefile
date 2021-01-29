##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	src/mul_matrix.c			\
		src/str_len.c				\
		src/my_str_to_word_array.c	\
		inv_mat.c					\
		test/main.c					\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
