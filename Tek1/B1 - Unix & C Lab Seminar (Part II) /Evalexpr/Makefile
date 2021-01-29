##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

DEPS=	include

SRC	=	lib/str_len.c	\
		lib/str_dup.c	\
		lib/put_char.c	\
		lib/put_str.c	\
		lib/put_nbr.c	\
		cleaner.c		\
		verifier.c		\
		parser.c		\
		displayer.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

%.o:	%.c
		$(CC) -c -o $@ $< -I$(DEPS) -g

all:	$(NAME)

$(NAME):$(OBJ)
		gcc -o $(NAME) $(OBJ) -I$(DEPS) -g

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: 	fclean all