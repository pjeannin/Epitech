##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS	=	include/

SRC	=	src/utils/base.c			\
		src/utils/put.c				\
		src/utils/nbr.c				\
		src/utils/str.c				\
		src/evalexpr/eval_expr.c		\
		src/evalexpr/verify_expr.c		\
		src/evalexpr/verify_exprp2.c	\
		src/evalexpr/verifier.c			\
		src/evalexpr/cleaner.c			\
		src/evalexpr/parser.c			\
		src/evalexpr/displayer.c		\
		src/bigint/bigint.c			\
		src/bigint/bigint_utils.c		\
		src/bigint/bigint_comparators.c		\
		src/bigint/bigint_operators.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

%.o:	%.c
	$(CC) -c -o $@ $< -I$(DEPS) -g

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -I${DEPS} -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
